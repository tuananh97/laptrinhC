<html>
   <head>
      <meta http-equiv="Content-Type" content="text/html; charset=UTF-8"/>
      <title>Quản lý giảng dạy </title>
      <?php
         //Kêt nối CSDL
              $con = mysqli_connect("localhost","root","1","giangday");
mysqli_set_charset($con,"utf8");

if (mysqli_connect_errno())
  {
  echo "MySQLi Connection was not established: " . mysqli_connect_error();
  }
      // Hàm tach ho dem
      function Chuanhoa($str, $type = NULL)
      {
          $str   = mb_strtolower($str, 'UTF-8'); //Chuyển về chữ thường
          $str   = trim($str);  //Lược bỏ khoảng trắng đầu và cuối chuỗi
          $array = explode(" ", $str); //Lược bỏ khoảng trắng thừa giữa các từ
          foreach ($array as $key => $value)
          {
              if (trim($value) == null)
              {
                  unset($array[$key]);
                  continue;
              }
              if ($type == "ten")  //Chuyển kí tự đầu mỗi từ thành chữ hoa
              {
                  $array[$key] = ucfirst($value);
              }
          }
          //Chuyển kí tự đầu thành chữ hoa
          $result = implode(" ", $array);
          return $result;
      }
      // Hàm tach ho dem
      function Tachten($name,$a)
      {
          $mangten  = explode(" ", $name);
          $sophantu = count($mangten);
          $ten      = $mangten[$sophantu - 1];
          $hodem    = $mangten[$sophantu - 2];
          if($a=="ten") return $ten;
          else if($a=="hodem") return $hodem;
      }
         // Hàm lấy dữ liệu từ CSDL và hiển thị
             function getData()
             {
                 global $giatri, $ketqua;
                 $giatri = "";
                 $query = "SELECT giangvien_monhoc.* FROM Giangvien_Monhoc INNER JOIN giangvien ON giangvien_monhoc.magiangvien=giangvien.magiangvien INNER JOIN monhoc ON giangvien_monhoc.mamonhoc=monhoc.mamonhoc";
                 $result = mysqli_query($con, $query);
                 for ($i = 0; $i < mysqli_num_rows($result); $i ++) {
                     $ketqua[$i] = mysqli_fetch_array($result);
		     $ngay = date("d/m/Y",strtotime($ketqua[$i]['ngaybatdau']));
                     $giatri .= "
                  <tr>
                  <td>" . ($i + 1) . "</td>
                  <td>" . $ketqua[$i]['tenmonhoc'] . "</td>
                  <td>" . $ketqua[$i]['tengiangvien'] . "</td>
			       <td> ".$ngay." </td>
				  <td><input type='checkbox' name='chonxoa[]' value=" . $i . " /></td>
                  <td><a href='sua.php?mamonhoc=". $ketqua[$i]['mamonhoc'] . "&magiangvien=". $ketqua[$i]['magiangvien'] . "'> Sửa </a></td>
                  </tr>
                  ";
                 }
             }
             getData();
			  
			 
         	 // Lấy dữ liệu từ form
             $giangvien = isset($_REQUEST['magiangvien']) ? $_REQUEST['magiangvien'] : '';
             $monhoc = isset($_REQUEST['mamonhoc']) ? $_REQUEST['mamonhoc'] : '';
             $ngaybatdau = isset($_REQUEST['ngaybatdau']) ? $_REQUEST['ngaybatdau'] : '';
			 
             // Lấy giá trị ở các ô checkbox
         
             $chonxoa = isset($_REQUEST['chonxoa']) ? $_REQUEST['chonxoa'] : 'off';
                    
             // Lấy sự kiện submit, khi click vào nút Xoa hoặc Cap nhat
             $cmd = isset($_REQUEST['in']) ? $_REQUEST['in'] : '';
         
            // Hàm Insert bản ghi
             function insertData($giangvien,$monhoc,$ngaybatdau)
             {
                 $query = "INSERT INTO giangvien_monhoc(magiangvien, mamonhoc,ngaybatdau) VALUES('" . $giangvien . "', '" .  $monhoc . "', '" .  $ngaybatdau . "')";
                 mysqli_query($con, $query);
             }
         
            // Hàm Delete bản ghi
             function deleteData($monhoc,$giangvien,$ngaybatdau)
             {
                 $query = "DELETE FROM Giangvien_Monhoc WHERE mamonhoc='" . $monhoc . "' AND magiangvien='" . $giangvien . "' AND ngaybatdau='" . $ngaybatdau . "'";
                 mysqli_query($con, $query);
             }
             if ($cmd == 'Thêm') { // Nếu click nút Xoa
                 insertData($giangvien,$monhoc,$ngaybatdau); // Thêm bản ghi vào bảng hoivien
                 getData(); // Gọi lại hàm để lấy dữ liệu và hiển thị sau khi thêm bản ghi
             } else if ($cmd == 'Xóa') { 
             // Nếu click nút Xóa
                 if ($chonxoa != 'off') {					 // Nếu ô checkbox đã được lựa chọn
                     for ($i = 0; $i < count($chonxoa); $i ++) {
         
                         deleteData($ketqua[$chonxoa[$i]]['mamonhoc'],$ketqua[$chonxoa[$i]]['magiangvien'],$ketqua[$chonxoa[$i]]['ngaybatdau']);
                         // Xóa bản ghi
                     }
                     getData(); // Gọi hàm để lấy dữ liệu và hiển thị sau khi xóa bản ghi
                 }	}
			   
				 // Hàm lấy dữ liệu từ CSDL và hiển thị
             function getData2()
             {
                 global $giatri2, $ketqua2;
                 $giatri2 = "";
                 $query2 = "SELECT giangvien.tengiangvien, COUNT(mamonhoc) as dem FROM giangvien_monhoc INNER JOIN giangvien ON giangvien_monhoc.magiangvien=giangvien.magiangvien GROUP BY giangvien_monhoc.magiangvien";
                 $result2 = mysqli_query($con, $query2);
                 $numrows2 = mysqli_num_rows($result2);
                 for ($i = 0; $i < $numrows2; $i ++) {
                     $ketqua2[$i] = mysqli_fetch_array($result2);
                     $giatri2 .= "
                  <tr>
                  <td>" . ($i + 1) . "</td>
                  <td>" . $ketqua2[$i]['tengiangvien'] . "</td>
				  <td>" . $ketqua2[$i]['dem'] . "</td>
                  </tr>
                  ";
                 }
             }
			 getData2();
             ?>
   </head>
   <body>
      <center>
         <h1>Quản lý giảng dạy</h1>
      </center>
      <table align="center" >
         <tr align="center">
            <td>
               <form name="form" method="POST">
                  <table>
				  
                     <tr>
					  <?php 
            $query1="SELECT * FROM monhoc";
            $KQ1=mysqli_query($con, $query1); 
            
            ?>
                        <td width="40%"><label>Môn học</label></td>
                        <td>
                     <select name="mamonhoc">
                    <?php
                    while($tenmonhoc = mysqli_fetch_array($KQ1))
                    {
                    ?>
                        <option value="<?php echo $tenmonhoc['mamonhoc'] ?>"><?php echo $tenmonhoc['tenmonhoc'] ?></option>
                    <?php 
                    } 
                    ?>
                 </select>
				 </td>
                     </tr>
					      <tr>
					  <?php 
            $query1="SELECT * FROM giangvien";
            $KQ2=mysqli_query($con, $query1); 
            
            ?>
                        <td width="40%">Giảng viên</td>
                        <td>
                     <select name="magiangvien">
                    <?php
                    while($tengiangvien = mysqli_fetch_array($KQ2))
                    {
                    ?>
                        <option value="<?php echo $tengiangvien['magiangvien'] ?>"><?php echo $tengiangvien['tengiangvien'] ?></option>
                    <?php 
                    } 
                    ?>
                 </select>
				 </td>
                     </tr>
                     <tr>
                         
                        <td width="30%">Ngày bắt đầu:</td>
                        <td><input type="date" name="ngaybatdau" /></td>
                     
                     </tr>
                     <tr align="center">
                        <td colspan="2">
                           <input type="submit" value="Thêm" name="in"/>'
                           <input type="submit" value="Xóa" name="in" onClick="return confirm('Bạn có thực sự muốn xóa')">
                        </td>
                        <td>&nbsp;</td>
                     </tr>
                  </table>
            </td>
           
         </tr>
		  <tr> 
		   <td>
            <table align="center" border="1px">
            <tr>
            <td>STT</td>
            <td>Môn học</td>
			<td>Giảng viên</td>
			<td>Ngày bắt đầu</td>
			<td>Chọn xóa</td>
            <td>Chọn sửa</td>
            </tr> 
            <?php
               global $giatri;
               echo $giatri;
             ?>	
            </table>					
            </td> 
		 </tr>
		  <tr> 
		   <td>
            <table align="center" border="1px">
            <tr>
            <td>STT</td>
			<td>Giảng viên</td>
			<td>Số môn học dạy</td>
            </tr> 
            <?php
               global $giatri2;
               echo $giatri2;
             ?>	
            </table>					
            </td> 
		 </tr>
		 
		 <?php
		    $query3 = "SELECT count(DISTINCT magiangvien) as sogiangvien FROM giangvien_monhoc";
            $result3 = mysqli_query($con, $query3);
            $kq = mysqli_fetch_array($result3);
			$sogv = $kq['sogiangvien'];
            $query4 = "SELECT COUNT(mamonhoc) as somonhoc FROM giangvien_monhoc";
            $result4 = mysqli_query($con, $query4);
            $kq1 = mysqli_fetch_array($result4);
			$somonhoc = $kq1['somonhoc'];
			echo "Danh sách gồm có ". $sogv. " giảng viên và " .$somonhoc." môn học";
		 ?>
		 
      </table>
   </body>
</html>
