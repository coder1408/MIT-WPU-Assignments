import React from "react";
import Button from "./Button";

const ButtonPanel = ({
  handleClick,
  handleClear,
  handleBackspace,
  handleEqual,
}) => (
  <div className="buttons">
    <Button value="1" onClick={handleClick} />
    <Button value="2" onClick={handleClick} />
    <Button value="3" onClick={handleClick} />
    <Button value="+" onClick={handleClick} />
    <Button value="4" onClick={handleClick} />
    <Button value="5" onClick={handleClick} />
    <Button value="6" onClick={handleClick} />
    <Button value="-" onClick={handleClick} />
    <Button value="7" onClick={handleClick} />
    <Button value="8" onClick={handleClick} />
    <Button value="9" onClick={handleClick} />
    <Button value="*" onClick={handleClick} />
    <Button value="0" onClick={handleClick} />
    <Button value="/" onClick={handleClick} /> {/* Division button added */}
    <Button value="C" onClick={handleClear} />
    <Button value="←" onClick={handleBackspace} />
    <Button value="=" onClick={handleEqual} />
  </div>
);

export default ButtonPanel;
