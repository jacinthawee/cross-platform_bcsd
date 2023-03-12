
int UI_ctrl(UI *ui,int cmd,long i,void *p,f *f)

{
  uint uVar1;
  uint uVar2;
  
  if (ui == (UI *)0x0) {
    ERR_put_error(0x28,0x6f,0x43,"ui_lib.c",0x20d);
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
    ERR_put_error(0x28,0x6f,0x6a,"ui_lib.c",0x21f);
  }
  return -1;
}

