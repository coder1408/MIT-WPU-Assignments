import React, { useState, useEffect } from "react";
import "./Calculator.css";

const Calculator = () => {
  const [input, setInput] = useState("");
  const [result, setResult] = useState("");

  // Keyboard support
  useEffect(() => {
    const handleKeyDown = (event) => {
      const { key } = event;
      if (key >= "0" && key <= "9") {
        handleClick(key);
      } else if (key === "+" || key === "-" || key === "*" || key === "/") {
        handleClick(key);
      } else if (key === "Enter") {
        handleEqual();
      } else if (key === "Backspace") {
        handleBackspace();
      } else if (key === "Escape") {
        handleClear();
      } else if (key === ".") {
        handleClick(".");
      }
    };

    window.addEventListener("keydown", handleKeyDown);

    return () => {
      window.removeEventListener("keydown", handleKeyDown);
    };
  }, [input]);

  const handleClick = (value) => {
    setInput((prev) => prev + value);
  };

  const handleClear = () => {
    setInput("");
    setResult("");
  };

  const handleBackspace = () => {
    setInput(input.slice(0, -1));
  };

  const handleEqual = () => {
    try {
      setResult(eval(input).toString());
    } catch (err) {
      setResult("Error");
    }
  };

  return (
    <div className="calculator">
      <div className="display">
        <input type="text" value={input} disabled />
        <div className="result">{result}</div>
      </div>
      <div className="buttons">
        <button onClick={handleClear}>C</button>
        <button onClick={handleBackspace}>←</button>
        <button onClick={() => handleClick("/")}>/</button>
        <button onClick={() => handleClick("*")}>*</button>
        <button onClick={() => handleClick("7")}>7</button>
        <button onClick={() => handleClick("8")}>8</button>
        <button onClick={() => handleClick("9")}>9</button>
        <button onClick={() => handleClick("-")}>-</button>
        <button onClick={() => handleClick("4")}>4</button>
        <button onClick={() => handleClick("5")}>5</button>
        <button onClick={() => handleClick("6")}>6</button>
        <button onClick={() => handleClick("+")}>+</button>
        <button onClick={() => handleClick("1")}>1</button>
        <button onClick={() => handleClick("2")}>2</button>
        <button onClick={() => handleClick("3")}>3</button>
        <button onClick={handleEqual}>=</button>
        <button onClick={() => handleClick("0")} className="zero">
          0
        </button>
        <button onClick={() => handleClick(".")}>.</button>
      </div>
    </div>
  );
};

export default Calculator;
