
undefined4 mem_free(int param_1)

{
  BUF_MEM *a;
  
  if (param_1 != 0) {
    if (((*(int *)(param_1 + 0x10) != 0) && (*(int *)(param_1 + 0xc) != 0)) &&
       (a = *(BUF_MEM **)(param_1 + 0x20), a != (BUF_MEM *)0x0)) {
      if ((*(byte *)(param_1 + 0x15) & 2) != 0) {
        a->data = (char *)0x0;
      }
      BUF_MEM_free(a);
      *(undefined4 *)(param_1 + 0x20) = 0;
    }
    return 1;
  }
  return 0;
}

