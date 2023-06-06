/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mansanch <mansanch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/06 16:00:35 by mansanch          #+#    #+#             */
/*   Updated: 2023/06/06 16:05:15 by mansanch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int isStackEmpty(Stack* stack) {
    return stack->top == -1;
}

int isStackFull(Stack* stack) {
    return stack->top == MAX_SIZE - 1;
}

void push(Stack* stack, int element) {
    if (isStackFull(stack)) {
        printf("Error: Stack overflow\n");
        exit(1);
    }
    stack->top++;
    stack->data[stack->top] = element;
}

int pop(Stack* stack) {
    if (isStackEmpty(stack)) {
        printf("Error: Stack underflow\n");
        exit(1);
    }
    int element = stack->data[stack->top];
    stack->top--;
    return element;
}

void pa(Stack* stackA, Stack* stackB) {
    if (!isStackEmpty(stackB)) {
        int element = pop(stackB);
        push(stackA, element);
    }
}

void pb(Stack* stackA, Stack* stackB) {
    if (!isStackEmpty(stackA)) {
        int element = pop(stackA);
        push(stackB, element);
    }
}

void sa(Stack* stackA) {
    if (stackA->top >= 1) {
        int temp = stackA->data[stackA->top];
        stackA->data[stackA->top] = stackA->data[stackA->top - 1];
        stackA->data[stackA->top - 1] = temp;
    }
}

void sb(Stack* stackB) {
    if (stackB->top >= 1) {
        int temp = stackB->data[stackB->top];
        stackB->data[stackB->top] = stackB->data[stackB->top - 1];
        stackB->data[stackB->top - 1] = temp;
    }
}

void ss(Stack* stackA, Stack* stackB) {
    sa(stackA);
    sb(stackB);
}

void ra(Stack* stackA) {
    if (!isStackEmpty(stackA)) {
        int element = pop(stackA);
        push(stackA, element);
    }
}

void rb(Stack* stackB) {
    if (!isStackEmpty(stackB)) {
        int element = pop(stackB);
        push(stackB, element);
    }
}

void rr(Stack* stackA, Stack* stackB) {
    ra(stackA);
    rb(stackB);
}

void rra(Stack* stackA) {
    if (!isStackEmpty(stackA)) {
        int element = stackA->data[0];
        int i = 0;
        while (i < stackA->top) {
            stackA->data[i] = stackA->data[i + 1];
            i++;
        }
        stackA->data[stackA->top] = element;
    }
}