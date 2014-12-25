Data Structures Library
=======================

<b>Data Structures implemented in C++</b>

<b>Sequence Containers</b><br>
1. Vector<br>
    &nbsp;&nbsp;vector < data_type > vector_identifier<br>
2. List<br>
    &nbsp;&nbsp;list < data_type > list_identifier<br>
3. Doubly List<br>
    &nbsp;&nbsp;doubly_list < data_type > doubly_list_identifier<br>

  Functions:<br>
    &nbsp;&nbsp;insert_front(data_type item)<br>
    &nbsp;&nbsp;insert_rear(data_type item)<br>
    &nbsp;&nbsp;insert(data_type item, int position)<br>
    &nbsp;&nbsp;pop_front()<br>
    &nbsp;&nbsp;pop_rear()<br>
    &nbsp;&nbsp;pop(int position)<br>
    &nbsp;&nbsp;get_pos(data_type item)<br>
  Accessing ith element: list_identifier[i] (Negative position to start from end)<br>
<br>
<b>Container Adaptors</b>
1. Stack<br>
    &nbsp;&nbsp;stack < data_type, Sequence Container > stack_identifier<br>
  Functions:<br>
    &nbsp;&nbsp;push(item)<br>
    &nbsp;&nbsp;pop()<br>
    &nbsp;&nbsp;get_top()<br>
2. Queue<br>
    &nbsp;&nbsp;queue < data_type, Sequence Container> queue_identifier<br>
  Functions:<br>
    &nbsp;&nbsp;enqueue(item)<br>
    &nbsp;&nbsp;dequeue()<br>
    &nbsp;&nbsp;get_front()<br>

<b>Associative Containers</b><br>
1. Binary Search Tree<br>
2. Graph<br>
3. Set<br>
