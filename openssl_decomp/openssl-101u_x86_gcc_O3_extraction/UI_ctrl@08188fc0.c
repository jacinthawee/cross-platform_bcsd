
int UI_ctrl(UI *ui,int cmd,long i,void *p,f *f)

{
  uint uVar1;
  uint uVar2;
  int reason;
  int line;
  
  if (ui == (UI *)0x0) {
    line = 0x20d;
    reason = 0x43;
  }
  else {
    if (cmd == 1) {
      uVar1 = *(uint *)(ui + 0x14);
      uVar2 = uVar1 >> 8 & 1;
      if (i != 0) {
        *(uint *)(ui + 0x14) = uVar1 | 0x100;
        return uVar2;
      }
      *(uint *)(ui + 0x14) = uVar1 & 0xfffffeff;
      return uVar2;
    }
    if (cmd == 2) {
      return *(uint *)(ui + 0x14) & 1;
    }
    line = 0x21f;
    reason = 0x6a;
  }
  ERR_put_error(0x28,0x6f,reason,"ui_lib.c",line);
  return -1;
}

