<?php

use App\QuestionGame;

$json = file_get_contents('php://input');
// Converts it into a PHP object
$data = json_decode($json);



if(!(strcmp($data->key , "34@_rteyknjvs#25x"))  and !(strcmp($data->password,"degree360"))){

	$questionGame = new QuestionGame();
	$response = $questionGame->respond($data->word);
    $data = [
    	'valid' => 1,
    	'question' => $data->word, 
    	'answer' => $response
	];
header('Content-type: text/javascript');
echo json_encode($data);
    
}
else{
    $data = array('valid' => 0,'reason' => "Wrong details. Adviced to Restart module!");
header('Content-type: text/javascript');
echo json_encode($data);
    
}