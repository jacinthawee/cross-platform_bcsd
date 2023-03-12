
void print_fp(BIO *param_1,undefined4 param_2,void *param_3)

{
  undefined *puVar1;
  BIO_METHOD *type;
  void *data;
  char *len;
  BIO BStack_5c;
  void *local_1c;
  
  puVar1 = PTR___stack_chk_guard_006a9ae8;
  local_1c = *(void **)PTR___stack_chk_guard_006a9ae8;
  type = BIO_s_file();
  BIO_set(&BStack_5c,type);
  BIO_ctrl(&BStack_5c,0x6a,0,param_3);
  len = "%s";
  BIO_printf(&BStack_5c,"%s");
  if (local_1c == *(void **)puVar1) {
    return;
  }
  data = local_1c;
  (*(code *)PTR___stack_chk_fail_006a9ab0)();
  BIO_write(param_1,data,(int)len);
  return;
}

