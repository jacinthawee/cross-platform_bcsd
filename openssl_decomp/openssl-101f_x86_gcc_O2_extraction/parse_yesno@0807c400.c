
undefined4 parse_yesno(undefined *param_1,undefined4 param_2)

{
  if (param_1 != (undefined *)0x0) {
    switch(*param_1) {
    case 0x30:
    case 0x46:
    case 0x4e:
    case 0x66:
    case 0x6e:
      param_2 = 0;
      break;
    case 0x31:
    case 0x54:
    case 0x59:
    case 0x74:
    case 0x79:
      return 1;
    }
  }
  return param_2;
}

