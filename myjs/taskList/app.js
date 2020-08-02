const form = document.querySelector('#task-form');
const taskList = document.querySelector('.collection');
const clearbtn = document.querySelector('.clear-tasks');
const filter = document.querySelector('#filter');
const taskInput = document.querySelector('#task');

loadEventListeners();

function loadEventListeners()
{
     // DOM load event
    document.addEventListener('DOMContentLoaded', getTasks);

     // Add Task event
    form.addEventListener('submit', addTask);
    
    // Remove Task event
    taskList.addEventListener('click', removeTask);
    
    // Clear Task event
    clearbtn.addEventListener('click', clearTasks);
    
    // Filter Tasks event
    filter.addEventListener('keyup', filterTasks);
}

// Get tasks from local storage
function getTasks(e)
{
    let tasks;
    if(localStorage.getItem('tasks') === null)
    {
        tasks = []
    }
    else
    {
        tasks = JSON.parse(localStorage.getItem('tasks'));
    }

    tasks.forEach(function(task)
    {
        const li = document.createElement('li');
        li.className = 'collectionItem';

        li.appendChild(document.createTextNode(task));
        const link = document.createElement('a');

        // If you want something to the right of a list item in materialize, it has to have 
        // secondary-content class
        link.className = 'delete-item secondary-content';

        link.innerHTML = '<i class="fa fa-remove"></i>';

        li.appendChild(link);
        taskList.appendChild(li);

    });
    
}



function addTask(e)
{
    if(taskInput.value === '')
    {
        alert('Add a Task');
    }

    else
    {
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

        
        storeTaskInLocalStorage(taskInput.value);
        
        taskInput.value='';

    }
    e.preventDefault();
}



function storeTaskInLocalStorage(task)
{
    let tasks;
    if(localStorage.getItem('tasks') === null)
    {
        tasks = [];
    }
    else
    {
        tasks = JSON.parse(localStorage.getItem('tasks'));
        
    }

    tasks.push(task);
    localStorage.setItem('tasks', JSON.stringify(tasks));


}




function removeTask(e)
{
    if(e.target.parentElement.classList.contains('delete-item'))
    {
        if(confirm('Are you sure about deleting'+' '+e.target.parentElement.parentElement.textContent))
        {
            e.target.parentElement.parentElement.remove();

            //remove from local storage
            removeTaskFromLocalStorage(e.target.parentElement.parentElement);

        }
            
    }
}



function removeTaskFromLocalStorage(taskItem)
{
    let tasks;
    if(localStorage.getItem('tasks') === null)
    {
        tasks = [];
    }
    else
    {
        tasks = JSON.parse(localStorage.getItem('tasks'));
    }

    tasks.forEach(function(task, index)
    {
        if(taskItem.textContent === task)
        {
            tasks.splice(index, 1);
        }
    });

    localStorage.setItem('tasks', JSON.stringify(tasks));


}



function clearTasks(e)
{
    // This alternative is slower
    // taskList.innerHTML = '';

    // This alternative is faster
    while(taskList.firstChild)
        taskList.removeChild(taskList.firstChild);


    // Clear tasks from local storage
    clearTasksFromLocalStorage();

}


function clearTasksFromLocalStorage()
{
    localStorage.clear()
}






function filterTasks(e)
{
    const text = e.target.value.toLowerCase();
    document.querySelectorAll('.collection-item').forEach
    (function(task){
            const item = task.firstChild.textContent;
            if(item.toLowerCase().indexOf(text) != -1)
            {   
                task.style.display = 'block';
            }
            else
            {
                task.style.display = 'none';
            }
        });
}



