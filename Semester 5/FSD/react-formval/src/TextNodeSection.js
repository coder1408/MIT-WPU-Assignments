import React, { useState } from "react";

function TextNodeSection() {
  const [parentNode, setParentNode] = useState(["Existing Text"]);

  const addTextNode = () => {
    setParentNode([...parentNode, "This is a new text node."]);
  };

  return (
    <div className="text-node-section">
      <div id="parentNode">
        {parentNode.map((text, index) => (
          <p key={index}>{text}</p>
        ))}
      </div>
      <button type="button" onClick={addTextNode}>
        Add Text Node
      </button>
    </div>
  );
}

export default TextNodeSection;
