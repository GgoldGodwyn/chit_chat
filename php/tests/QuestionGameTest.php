<?php
namespace UnitTestFiles\Test;
use PHPUnit\Framework\TestCase;
use App\QuestionGame;


class FirstTest extends TestCase
{
    /** @test **/
	public function testSuccessfulResponse()
	{
		$questionGame = new QuestionGame();
		$response = $questionGame->respond(1);

		$this->assertIsString($response);
	}
}