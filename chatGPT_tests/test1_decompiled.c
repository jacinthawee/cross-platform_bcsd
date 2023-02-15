
int my_func(int param_1)

{
  int local_10;
  int local_c;
  
  local_10 = 1;
  for (local_c = 1; local_c <= param_1; local_c = local_c + 1) {
    local_10 = local_10 * local_c;
  }
  return local_10;
}

