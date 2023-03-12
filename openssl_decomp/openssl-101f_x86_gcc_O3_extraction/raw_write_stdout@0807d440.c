
void raw_write_stdout(void *param_1,size_t param_2)

{
  int __fd;
  
  __fd = fileno(stdout);
  write(__fd,param_1,param_2);
  return;
}

