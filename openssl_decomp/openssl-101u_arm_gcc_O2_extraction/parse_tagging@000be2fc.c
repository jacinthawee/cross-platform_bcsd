
undefined4 parse_tagging(char *param_1,int param_2,ulong *param_3,undefined4 *param_4)

{
  ulong uVar1;
  undefined4 uVar2;
  char local_20;
  undefined local_1f;
  char *local_1c;
  
  if (param_1 == (char *)0x0) {
    return 0;
  }
  uVar1 = strtoul(param_1,&local_1c,10);
  if (((local_1c == (char *)0x0) || (*local_1c == '\0')) || (local_1c <= param_1 + param_2)) {
    if (-1 < (int)uVar1) {
      *param_3 = uVar1;
      if ((local_1c == (char *)0x0) || (param_1 + (param_2 - (int)local_1c) == (char *)0x0)) {
        uVar2 = 1;
        *param_4 = 0x80;
      }
      else {
        local_20 = *local_1c;
        switch(local_20) {
        case 'A':
          uVar2 = 1;
          *param_4 = 0x40;
          break;
        default:
          uVar2 = 0;
          local_1f = 0;
          ERR_put_error(0xd,0xb6,0xba,"asn1_gen.c",0x1bb);
          ERR_add_error_data(2,"Char=",&local_20);
          break;
        case 'C':
          uVar2 = 1;
          *param_4 = 0x80;
          break;
        case 'P':
          uVar2 = 1;
          *param_4 = 0xc0;
          break;
        case 'U':
          uVar2 = 1;
          *param_4 = 0;
        }
      }
      return uVar2;
    }
    ERR_put_error(0xd,0xb6,0xbb,"asn1_gen.c",0x19c);
  }
  return 0;
}

