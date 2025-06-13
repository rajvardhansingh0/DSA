def max_element(stack):
    if not stack:
        return None
    max_val = stack[0]
    for x in stack:
        if x > max_val:
            max_val = x
    return max_val