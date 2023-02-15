
void do_a(int param_1)

{
  int local_1c;
  int local_18;
  int local_14;
  
  local_1c = 10;
  if (param_1 < 10) {
    local_18 = param_1 + 2;
  }
  else {
    local_18 = 2 - param_1;
  }
  printf("The sum is %d",(ulong)(local_18 + 10));
  putchar(10);
  printf("The difference is %d",(ulong)(10 - local_18));
  putchar(10);
  for (local_14 = 0; local_14 < 5; local_14 = local_14 + 1) {
    local_1c = local_1c + local_14;
  }
  printf("The new sum is %d",(ulong)(uint)(local_18 + local_1c));
  putchar(10);
  return;
}

