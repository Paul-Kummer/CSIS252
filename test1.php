<!-- 1 seg A -->
<?php
function copy_array1(&$dest,&$src) 
{
	foreach($src as $key=>$value) 
	{
		$dest[$key] = $value;
	};
	return 1;
};

$a = array(1,2,3);
$b = array(4,5,6);
copy_array1($b,$a);
print_r($b);

function copy_array2(&$dest,&$src,$amount,$src_offset,$dest_offset) 
{
	for ($i = 0; $i < $amount; $i++) 
	{
		$dest[$dest_offset + $i] = $src[$src_offset + $i];
	};
	return 1;
};

copy_array2($a,$b,1,1,2);
print_r($a);
$c = array(1,2,3,4,5,6,7,8);
copy_array2($c,$c,3,1,4);
print_r($c);
?>


<!-- 2 seg B -->
<?php
session_start();
extract($_SESSION);
foo($_SESSION["bar"]);
echo $bar;
function foo($bar) 
{
	$bar = 1;
};
?>


<!-- 3 seg C -->
<form>
<?php
$a = array();
extract($_REQUEST);
array_push($a,$b);
print_r($a);
echo <<< HERE
<input type="submit">
<input type="text" name="b">
HERE;

for ($i = 0; $i < count($a); $i++) 
{
echo <<< HERE
	<input type="hidden" name="a[$i]" value="$a[$i]">
HERE;
};
?>
</form>


<!-- 4 seg D -->
<form>
<?php
$left = array();
$right = array();
$current = 0;
session_start();
extract($_SESSION);
extract($_REQUEST);

if ($button == "Left") move_left();
if ($button == "Right") move_right();
if ($button == "Toggle") toggle();

$_SESSION["left"] = $left;
$_SESSION["right"] = $right;
$_SESSION["current"] = $current;

echo <<<HERE
	<input type="submit" name="Left">
	<input type="submit" name="Right">
	<input type="submit" name="Toggle">
	$current
HERE;

function move_left(&$left,&$right,&$current) 
{
	array_push($right,$current);
	$current = array_pop($left);
};

function move_right(&$left,&$right,&$current) 
{
	array_push($left,$current);
	$current = array_pop($right);
};

function toggle(&$left,&$right,&$current) 
{
	$current = 1 - $current;
};
?>
</form>