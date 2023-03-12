
size_t mem_ctrl(int param_1,int param_2,undefined4 param_3,BUF_MEM **param_4)

{
  size_t sVar1;
  char *pcVar2;
  BUF_MEM *a;
  
  a = *(BUF_MEM **)(param_1 + 0x20);
  if (param_2 == 10) {
    return a->length;
  }
  if (param_2 < 0xb) {
    if (param_2 == 3) {
      sVar1 = a->length;
      if (param_4 == (BUF_MEM **)0x0) {
        return sVar1;
      }
      *param_4 = (BUF_MEM *)a->data;
      return sVar1;
    }
    if (3 < param_2) {
      if (param_2 == 8) {
        return *(size_t *)(param_1 + 0x10);
      }
      if (param_2 != 9) {
        return 0;
      }
      *(undefined4 *)(param_1 + 0x10) = param_3;
      return 1;
    }
    if (param_2 == 1) {
      pcVar2 = a->data;
      if (pcVar2 == (char *)0x0) {
        return 1;
      }
      if ((*(uint *)(param_1 + 0x14) & 0x200) != 0) {
        sVar1 = a->length;
        a->length = a->max;
        a->data = pcVar2 + (sVar1 - a->max);
        return 1;
      }
      (*(code *)PTR_memset_006a99f4)(pcVar2,0,a->max,param_4,&_gp);
      a->length = 0;
      return 1;
    }
    if (param_2 == 2) {
      return (uint)(a->length == 0);
    }
  }
  else {
    if (param_2 == 0x72) {
      if (((*(int *)(param_1 + 0x10) != 0) && (*(int *)(param_1 + 0xc) != 0)) &&
         (a != (BUF_MEM *)0x0)) {
        if ((*(uint *)(param_1 + 0x14) & 0x200) != 0) {
          a->data = (char *)0x0;
        }
        BUF_MEM_free(a);
      }
      *(undefined4 *)(param_1 + 0x10) = param_3;
      *(BUF_MEM ***)(param_1 + 0x20) = param_4;
      return 1;
    }
    if (param_2 < 0x73) {
      if (0xc < param_2) {
        return 0;
      }
      return 1;
    }
    if (param_2 == 0x73) {
      if (param_4 != (BUF_MEM **)0x0) {
        *param_4 = a;
        return 1;
      }
      return 1;
    }
    if (param_2 == 0x82) {
      *(undefined4 *)(param_1 + 0x1c) = param_3;
      return 1;
    }
  }
  return 0;
}

