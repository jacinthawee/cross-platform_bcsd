
int my_f(int param_1)

{
  int local_1c;
  int local_c;
  
  local_c = param_1;
  for (local_1c = param_1; 1 < local_1c; local_1c = local_1c + -1) {
    local_c = local_c * (local_1c + -1);
  }
  return local_c;
}

