<?

$counters = array("clicks", "pops", "glitches");

while(true) {
  $counter = rand() % 10;
  $file = fopen(sprintf('/tmp/counters-%02d', $counter), 'w');
  
  for ($i = 0; $i < 10; $i++) {
    fputs($file, $counters[rand() % 3]."\n");
  }

  fclose($file);
}

?>