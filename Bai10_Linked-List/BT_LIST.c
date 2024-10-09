#include <stdio.h>
#include <stdlib.h>

typedef struct Node
{
    int data;
    struct Node *next;
} Node;

void *createNode(int data)
{
    Node *temp = (Node *)malloc(sizeof(Node));
    temp->data = data;
    temp->next = NULL;

    return temp;
}

// Hàm thêm 1 node ở cuối LIST
void push_back(Node **array, int value)
{
    Node *temp = createNode(value);

    if (*array == NULL)
    {
        temp = *array;
    }

    else
    {
        Node *p;
        while (p->next != NULL)
        {
            p = p->next;
        }
        p->next = temp;
    }
}

// Hàm xóa 1 node ở cuối LIST
void pop_back(Node **array)
{
    Node *p = *array;
    Node *temp;
    int i = 0;

    while (p->next != NULL)
    {
        p = p->next;
        i++;
    }
    free(p);

    int j;
    temp = *array;
    for (j = 0; j < i - 1; j++)
    {
        temp = temp->next;
    }
    temp->next = NULL;
}

// Hàm thêm 1 node ở đầu LIST
void push_front(Node **array, int value)
{
    Node *new_node = createNode(value);

    new_node->next = *array;
    *array = new_node;
}

// Hàm xóa 1 node ở đầu LIST
void pop_front(Node **array)
{
    if (*array == NULL)
    {
        return;
    }
    Node *temp = *array;
    *array = (*array)->next;
    free(temp);
}

// Hàm thêm 1 node vị trí bất kỳ trong LIST
void insert(Node **array, int value, int pos)
{
    Node *new_node = createNode(value);
    Node *p = *array;
    int index = 0;

    while (p->next != NULL && index != pos - 1)
    {
        p = p->next;
        index++;
    }

    if (index == pos - 1)
    {
        new_node->next = (p->next);
        p->next = new_node;
    }
}

// Hàm xóa 1 node ở vị trí bất kỳ LIST
void delete_list(Node **array, int pos)
{
    // Node **array: là con trỏ, trỏ đến con trỏ đầu của danh sách
    Node *p = *array;
    if (*array == NULL)
        return;
    if (pos == 0)
    {
        *array = p->next;
        free(p);
        return;
    }

    // Duyệt qua danh sách để tìm node node trước vị trí cần xóa
    int i;

    /* For tìm vị trí trước node cần xóa(pos-1)
     * p: Là con trỏ trỏ đến *node đứng trước* node mà ta muốn xóa
     * Kèm điều kiện, con trỏ của node đó không phải trỏ NULL
     * Thỏa đk, thì nó sẽ duyệt đến từng node tiếp theo.
     */
    for (i = 0; i < pos - 1 && p != NULL; i++)
    {
        p = p->next;
    }

    // Kiểm tra nếu vị trí cần xóa không hợp lệ
    /* Sau khi duyệt, nếu p == NULL ->> là vị trí cuối
     * hoặc vị trí tiếp theo == NULL ->> k tồn tại
     * ==>> Vượt quá chiều dài danh sách, hàm thoát ra, k thực thi
     */
    if (p == NULL || p->next == NULL)
        return;

    // Tìm được node cần xóa
    /* Sau khi tìm được node cần xóa (temp)
     * Cập nhật lại con trỏ của node trước đó (p->next)
     * Trỏ tới node sau khi bị xóa (temp-> next)
     */
    /* Giải thích cách khác
     * p:  trc node cần xóa
     * p->next: node cần xóa (ta lưu con trỏ tạm vào biến temp)
     * ==> Cho temp, trỏ đến node mà ta muốn xóa (temp-> next)
     */
    Node *temp = p->next;
    p->next = temp->next;

    free(temp);
}

// Hàm lấy giá trị của Node, tại 1 vị trí bất kỳ
int get(Node *array, int pos)
{
    int i = 0;

    while (array->next != NULL && pos != i)
    {
        array = array->next;
        i++;
    }

    if (pos != i)
    {
        printf("Error: List has less element\n");
        return 0;
    }

    int data = array->data;
    return data;
}

void printlist(Node *array)
{
    Node *p = array;
    int i = 0;

    while (p != NULL)
    {
        printf("Node %d - Data = %d\n", i, p->data);
        p = p->next;
        i++;
    }
}
int main(int argc, char const *argv[])
{
    Node *n1 = createNode(1);
    Node *n2 = createNode(2);
    Node *n3 = createNode(3);

    n1->next = n2;
    n2->next = n3;

    // push_front(&n1, 10);
    // insert(&n1, 1000, 2);
    // push_back(&n1, 15);
    // pop_back(&n1);

    // pop_back(&n1);
    // pop_front(&n1);2
    // delete_list(1&n1, 2);

    printlist(n1);

    int pos;
    printf("\nEnter the position to get the value: ");
    scanf("%d", &pos);

    // Lấy giá trị tại vị trí nhập vào
    int value = get(n1, pos);
    if (value != 0)
    {
        printf("Value at position %d: %d\n", pos, value);
    }
    return 0;
}
