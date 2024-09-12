import React from "react";

const Display = ({ input, result }) => (
  <div className="display">
    <input type="text" value={input} disabled />
    <div className="result">{result}</div>
  </div>
);

export default Display;
