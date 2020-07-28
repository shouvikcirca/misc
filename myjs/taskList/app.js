const form = document.querySelector('#task-form');
const taskList = document.querySelector('.collection');
const clearbtn = document.querySelector('.clear-tasks');
const filter = document.querySelector('#filter');
const taskInput = document.querySelector('#task');

loadEventListeners();

function loadEventListeners()
{
    form.addEventListener('submit', addTask);
}




function addTask(e)
{
    if(taskInput.value === '')
    {
        alert('Add a Task');
    }

    // In Materialize if you want the ul's to look good your ul should have a class 'collection' 
    // and the li's in it should have a class 'collectionItem' 
    const li = document.createElement('li');
    li.className = 'collectionItem';

    li.appendChild(document.createTextNode(taskInput.value));
    const link = document.createElement('a');

    // If you want something to the right of a list item in materialize, it has to have 
    // secondary-content class
    link.className = 'delete-item secondary-content';

    link.innerHTML = '<i class="fa fa-remove"></i>';

    li.appendChild(link);
    taskList.appendChild(li);

    taskInput.value='';

    e.preventDefault();
}

