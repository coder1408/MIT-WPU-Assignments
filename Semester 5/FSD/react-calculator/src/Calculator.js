import React, { useState, useEffect } from "react";
import Display from "./Display";
import ButtonPanel from "./ButtonPanel";
import "./Calculator.css";

const Calculator = () => {
  const [input, setInput] = useState("");
  const [result, setResult] = useState("");

  useEffect(() => {
    const handleKeyDown = (event) => {
      if (event.key === "Enter") {
        handleEqual();
      } else if (event.key === "Backspace") {
        handleBackspace();
      } else if (event.key === "Escape") {
        handleClear();
      } else {
        // Prevent multiple operators being added consecutively (optional enhancement)
        const operators = ["+", "-", "*", "/"];
        if (
          operators.includes(event.key) &&
          operators.includes(input[input.length - 1])
        ) {
          return;
        }
        setInput((prev) => prev + event.key);
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
      if (input.includes("/0")) {
        setResult("Error"); // Prevent division by zero
      } else {
        setResult(eval(input).toString());
      }
    } catch (err) {
      setResult("Error");
    }
  };

  return (
    <div className="calculator">
      <Display input={input} result={result} />
      <ButtonPanel
        handleClick={handleClick}
        handleClear={handleClear}
        handleBackspace={handleBackspace}
        handleEqual={handleEqual}
      />
    </div>
  );
};

export default Calculator;
