
int UI_ctrl(UI *ui,int cmd,long i,void *p,f *f)

{
  uint uVar1;
  uint uVar2;
  
  if (ui == (UI *)0x0) {
    (*(code *)PTR_ERR_put_error_006a9030)(0x28,0x6f,0x43,"ui_lib.c",0x229);
  }
  else {
    if (cmd == 1) {
      uVar2 = *(uint *)(ui + 0x14);
      uVar1 = (uVar2 << 0x17) >> 0x1f;
      if (i != 0) {
        *(uint *)(ui + 0x14) = uVar2 | 0x100;
        return uVar1;
      }
      *(uint *)(ui + 0x14) = uVar2 & 0xfffffeff;
      return uVar1;
    }
    if (cmd == 2) {
      return *(uint *)(ui + 0x14) & 1;
    }
    (*(code *)PTR_ERR_put_error_006a9030)(0x28,0x6f,0x6a,"ui_lib.c",0x23c);
  }
  return -1;
}

