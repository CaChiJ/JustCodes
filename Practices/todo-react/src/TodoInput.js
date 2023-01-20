import { useState } from "react";
import PropTypes from "prop-types";

export function TodoInput({ onSubmit }) {
  const [input, setInput] = useState("");

  const onChangeInput = (event) => {
    setInput(event.target.value);
  };

  const onSubmitInput = (event) => {
    event.preventDefault();

    if (input === "") {
      return;
    }

    onSubmit(input);
    setInput("");
  }
  
  return (
    <form onSubmit={ onSubmitInput }>
      <input 
        value={ input }
        onChange={ onChangeInput } 
        type="text"
      />
      <button type="submit">Add</button>
    </form>
  );
}


TodoInput.propTypes = {
  onSubmit: PropTypes.func.isRequired
}