import { useState } from "react";

import { TodoInput } from "./TodoInput";
import { TodoList } from "./TodoList";

function App() {
  const [todos, setTodos] = useState([]);

  const onSubmit = (input) => {
    setTodos((todos) => [input, ...todos]);
  }

  const onDelete = (index) => {
    setTodos((todos) => todos.filter((todo, i) => i !== index))
  }

  return (
    <div>
      <h1>To Do</h1>
      <TodoInput onSubmit={ onSubmit } />
      <TodoList todos={ todos } onDelete={ onDelete } />
    </div>
  );
}


export default App;
