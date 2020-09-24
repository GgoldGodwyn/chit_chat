<?php

namespace App;

/**
 * 
 */
class QuestionGame
{
   public function respond($question)
   {
       switch ($question) {
        case 0:
            return "hi\n";
        break;
        case 1:
            return "am fine. doing great!!\n";
        break;
        case 2:
            return "we are on vacation\n";
        break;
        case 3:
            return "am godwin's robot\n";
        break;
        case 4:
            return "that not a name\n";
        break;
        case 5:
            return "am was created 22nd-08-2019\n";
        break;
        case 6:
            return "am pleased, dont go yet, i have got some info i wid love to share with you\n";
        break;
        default:
            return "i dont understand\n" ;
       }
   }
   public function ask($n)
   {
       $write;
    do{
    if(strcmp("hello",$n)==0)
    $write=0;
    else if(strcmp("how are you doing",$n)==0)
    $write=1;
    else if(strcmp("did you go to school",$n)==0)
    $write=2;
    else if(strcmp("what is you name",$n)==0)
    $write=3;
    else if(strcmp("what a lovely name",$n)==0)
    $write=4;
    else if(strcmp("how old are you",$n)==0)
    $write=5;
    else if(strcmp("bye",$n)==0)
    $write=6;
    else
    $write=7;
    
        if($write>=0 && $write<=7){
            return $this->respond($write);
            $write=0;
        }
        
    }
    while($write!=0);
   }
}