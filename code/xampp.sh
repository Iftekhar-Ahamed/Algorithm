echo "[1] Start Xampp [2] Status Xampp [3] Stop Xampp";
read op
if [ $op = "1" ]; then
   sudo /opt/lampp/lampp start
 elif [ $op = "2" ]; then 
   sudo /opt/lampp/lampp status
elif [ $op = "3" ]; then 
  sudo /opt/lampp/lampp stop
fi
