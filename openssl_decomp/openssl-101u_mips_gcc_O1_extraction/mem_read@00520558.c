
uint mem_read(BIO *param_1,int param_2,uint param_3)

{
  uint uVar1;
  uint *puVar2;
  
  puVar2 = (uint *)param_1->ptr;
  BIO_clear_flags(param_1,0xf);
  uVar1 = *puVar2;
  if (-1 < (int)param_3) {
    if (uVar1 < param_3) {
      param_3 = uVar1;
    }
    if ((param_2 != 0) && (param_3 != 0)) {
      (*(code *)PTR_memcpy_006a9aec)(param_2,puVar2[1],param_3);
      uVar1 = param_1->flags;
      *puVar2 = *puVar2 - param_3;
      if ((uVar1 & 0x200) != 0) {
        puVar2[1] = puVar2[1] + param_3;
        return param_3;
      }
      (*(code *)PTR_memmove_006a9af4)(puVar2[1],puVar2[1] + param_3);
      return param_3;
    }
  }
  if ((uVar1 == 0) && (param_3 = param_1->num, param_3 != 0)) {
    BIO_set_flags(param_1,9);
    return param_3;
  }
  return param_3;
}

