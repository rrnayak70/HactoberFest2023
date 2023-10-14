let ulTasks=$('#ulTasks')
let btnAdd=$('#btnAdd')
let btnClear=$('#btnClear')
let inpNewTask=$('#inpnewTask')

btnAdd.click(()=>{
    let listItems = $('<li>',{
        'class': 'waves-effect col s12',
        
        text: inpNewTask.val()
    })
    listItems.click(()=>{
        listItems.toggleClass('disabled')
    })
    ulTasks.append(listItems)
    inpNewTask.val('')
})

btnClear.click(()=>inpNewTask.val(''))