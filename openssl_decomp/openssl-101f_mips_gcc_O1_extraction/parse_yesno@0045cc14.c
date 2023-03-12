
undefined4 parse_yesno(char *param_1,undefined4 param_2)

{
  if (param_1 != (char *)0x0) {
    switch(*param_1 + -0x30) {
    case '\0':
    case '\x16':
    case '\x1e':
    case '6':
    case '>':
      param_2 = 0;
      break;
    case '\x01':
    case '$':
    case ')':
    case 'D':
    case 'I':
      return 1;
    }
  }
  return param_2;
}

