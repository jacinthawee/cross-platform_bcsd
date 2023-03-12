
size_t mem_read(BIO *param_1,void *param_2,size_t param_3)

{
  byte bVar1;
  uint *puVar2;
  uint uVar3;
  
  puVar2 = (uint *)param_1->ptr;
  BIO_clear_flags(param_1,0xf);
  uVar3 = *puVar2;
  if (-1 < (int)param_3) {
    if (uVar3 < param_3) {
      param_3 = uVar3;
    }
    if ((param_2 != (void *)0x0) && (0 < (int)param_3)) {
      memcpy(param_2,(void *)puVar2[1],param_3);
      uVar3 = *puVar2;
      bVar1 = *(byte *)((int)&param_1->flags + 1);
      *puVar2 = uVar3 - param_3;
      if ((bVar1 & 2) != 0) {
        puVar2[1] = puVar2[1] + param_3;
        return param_3;
      }
      memmove((void *)puVar2[1],(void *)((int)(void *)puVar2[1] + param_3),uVar3 - param_3);
      return param_3;
    }
  }
  if ((uVar3 == 0) && (param_3 = param_1->num, param_3 != 0)) {
    BIO_set_flags(param_1,9);
    return param_3;
  }
  return param_3;
}

