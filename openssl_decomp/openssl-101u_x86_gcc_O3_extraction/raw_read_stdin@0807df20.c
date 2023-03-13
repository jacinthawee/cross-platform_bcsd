
void raw_read_stdin(void *param_1,size_t param_2)

{
  int __fd;
  
  __fd = fileno(stdin);
  read(__fd,param_1,param_2);
  return;
}

