import PropTypes from "prop-types";

import styles from "./TodoList.module.css";

export function TodoList({ todos, onDelete }) {
    return todos.map((todo, index) => (
        <div className={ styles.todoElement } key={ index }>
            <span>{todo}</span>
            <span onClick={ (event) => onDelete(index) }>❌</span>
        </div>
    ));
}

TodoList.propTypes = {
    todos: PropTypes.arrayOf(PropTypes.string).isRequired,
    onDelete: PropTypes.func
}