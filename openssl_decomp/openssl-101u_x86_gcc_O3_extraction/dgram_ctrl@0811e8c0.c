
size_t dgram_ctrl(int param_1,undefined4 param_2,size_t param_3,undefined4 *param_4)

{
  undefined4 *__src;
  undefined4 uVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  uint uVar4;
  size_t sVar5;
  int iVar6;
  int in_GS_OFFSET;
  int __optname;
  int local_48;
  socklen_t local_44;
  size_t local_40;
  sockaddr local_3c;
  int local_20;
  
  local_20 = *(int *)(in_GS_OFFSET + 0x14);
  local_48 = 0;
  __src = *(undefined4 **)(param_1 + 0x20);
  switch(param_2) {
  case 8:
    param_3 = *(size_t *)(param_1 + 0x10);
    break;
  case 9:
    *(size_t *)(param_1 + 0x10) = param_3;
    param_3 = 1;
    break;
  default:
    goto switchD_0811e8f2_caseD_a;
  case 0xb:
  case 0xc:
    goto switchD_0811e8f2_caseD_b;
  case 0x1f:
  case 0x2c:
switchD_0811e8f2_caseD_1f:
    if ((*(short *)param_4 == 2) || (*(short *)param_4 != 10)) {
      uVar3 = *param_4;
      uVar1 = param_4[1];
      uVar2 = param_4[2];
      __src[3] = param_4[3];
      *__src = uVar3;
      param_3 = 1;
      __src[1] = uVar1;
      __src[2] = uVar2;
    }
    else {
      *__src = *param_4;
      __src[1] = param_4[1];
      __src[2] = param_4[2];
      __src[3] = param_4[3];
      __src[4] = param_4[4];
      __src[5] = param_4[5];
      __src[6] = param_4[6];
      param_3 = 1;
    }
    break;
  case 0x20:
    if (param_4 != (undefined4 *)0x0) {
      __src[7] = 1;
      goto switchD_0811e8f2_caseD_1f;
    }
    __src[7] = 0;
    *__src = 0;
    __src[6] = 0;
    uVar4 = 0;
    do {
      *(undefined4 *)(((uint)(__src + 1) & 0xfffffffc) + uVar4) = 0;
      uVar4 = uVar4 + 4;
    } while (uVar4 < ((int)__src + (0x1c - ((uint)(__src + 1) & 0xfffffffc)) & 0xfffffffc));
    goto switchD_0811e8f2_caseD_b;
  case 0x21:
    iVar6 = 0x14;
    goto LAB_0811eb00;
  case 0x22:
    iVar6 = 0x14;
    goto LAB_0811e9d3;
  case 0x23:
    iVar6 = 0x15;
LAB_0811eb00:
    iVar6 = setsockopt(*(int *)(param_1 + 0x1c),1,iVar6,param_4,8);
    if (iVar6 < 0) {
      perror("setsockopt");
      param_3 = 0xffffffff;
      break;
    }
switchD_0811e8f2_caseD_b:
    param_3 = 1;
    break;
  case 0x24:
    iVar6 = 0x15;
LAB_0811e9d3:
    local_40 = 8;
    iVar6 = getsockopt(*(int *)(param_1 + 0x1c),1,iVar6,param_4,&local_40);
    param_3 = local_40;
    if (iVar6 < 0) {
      perror("getsockopt");
      param_3 = 0xffffffff;
    }
    break;
  case 0x25:
  case 0x26:
    if (__src[8] == 0xb) {
LAB_0811e98e:
      __src[8] = 0;
      goto switchD_0811e8f2_caseD_b;
    }
    goto switchD_0811e8f2_caseD_a;
  case 0x27:
    local_40 = 0x1c;
    uVar4 = 0;
    do {
      *(undefined4 *)(local_3c.sa_data + (uVar4 - 2)) = 0;
      uVar4 = uVar4 + 4;
    } while (uVar4 < 0x1c);
    iVar6 = getsockname(*(int *)(param_1 + 0x1c),&local_3c,&local_40);
    if (-1 < iVar6) {
      if (local_3c.sa_family == 2) {
        __optname = 10;
        iVar6 = 0;
      }
      else {
        if (local_3c.sa_family != 10) goto LAB_0811ec18;
        __optname = 0x17;
        iVar6 = 0x29;
      }
      local_48 = 2;
      iVar6 = setsockopt(*(int *)(param_1 + 0x1c),iVar6,__optname,&local_48,4);
      if (iVar6 < 0) {
        perror("setsockopt");
      }
      goto LAB_0811ec18;
    }
    goto switchD_0811e8f2_caseD_a;
  case 0x28:
LAB_0811ec18:
    local_40 = 0x1c;
    uVar4 = 0;
    do {
      *(undefined4 *)(local_3c.sa_data + (uVar4 - 2)) = 0;
      uVar4 = uVar4 + 4;
    } while (uVar4 < 0x1c);
    iVar6 = getsockname(*(int *)(param_1 + 0x1c),&local_3c,&local_40);
    if (-1 < iVar6) {
      local_44 = 4;
      if (local_3c.sa_family == 2) {
        iVar6 = getsockopt(*(int *)(param_1 + 0x1c),0,0xe,&local_48,&local_44);
        if ((-1 < iVar6) && (-1 < local_48)) {
          param_3 = local_48 - 0x1c;
          __src[9] = param_3;
          break;
        }
      }
      else if (((local_3c.sa_family == 10) &&
               (iVar6 = getsockopt(*(int *)(param_1 + 0x1c),0x29,0x18,&local_48,&local_44),
               -1 < iVar6)) && (-1 < local_48)) {
        param_3 = local_48 - 0x30;
        __src[9] = param_3;
        break;
      }
    }
    goto switchD_0811e8f2_caseD_a;
  case 0x29:
    param_3 = __src[9];
    break;
  case 0x2a:
    __src[9] = param_3;
    break;
  case 0x2b:
    if (__src[8] == 0x5a) goto LAB_0811e98e;
switchD_0811e8f2_caseD_a:
    param_3 = 0;
    break;
  case 0x2d:
    uVar3 = param_4[1];
    __src[10] = *param_4;
    __src[0xb] = uVar3;
    param_3 = 1;
    break;
  case 0x2e:
    sVar5 = 0x10;
    if (*(short *)__src == 10) {
      sVar5 = 0x1c;
    }
    if ((param_3 != 0) && ((int)param_3 <= (int)sVar5)) {
      sVar5 = param_3;
    }
    param_3 = sVar5;
    memcpy(param_4,__src,param_3);
    break;
  case 0x2f:
    param_3 = 0x224;
    if (*(short *)__src == 10) {
      iVar6 = 0x30;
      if (__src[2] == 0) {
        if ((__src[3] == 0) && (__src[4] == -0x10000)) {
          iVar6 = 0x1c;
        }
        if ((__src[3] == 0) && (__src[4] == -0x10000)) {
          param_3 = 0x240 - iVar6;
          break;
        }
      }
      param_3 = 0x500 - iVar6;
    }
    break;
  case 0x31:
    param_3 = 0x1c;
    if ((((*(short *)__src == 10) && (param_3 = 0x30, __src[2] == 0)) && (__src[3] == 0)) &&
       (__src[4] == -0x10000)) {
      param_3 = 0x1c;
    }
    break;
  case 0x68:
    if (*(int *)(param_1 + 0x10) != 0) {
      if (*(int *)(param_1 + 0xc) != 0) {
        shutdown(*(int *)(param_1 + 0x1c),2);
        close(*(int *)(param_1 + 0x1c));
      }
      *(undefined4 *)(param_1 + 0xc) = 0;
      *(undefined4 *)(param_1 + 0x14) = 0;
    }
    uVar3 = *param_4;
    *(undefined4 *)(param_1 + 0xc) = 1;
    *(undefined4 *)(param_1 + 0x1c) = uVar3;
    *(size_t *)(param_1 + 0x10) = param_3;
    param_3 = 1;
    break;
  case 0x69:
    if (*(int *)(param_1 + 0xc) == 0) {
      param_3 = 0xffffffff;
    }
    else {
      if (param_4 != (undefined4 *)0x0) {
        *param_4 = *(undefined4 *)(param_1 + 0x1c);
      }
      param_3 = *(size_t *)(param_1 + 0x1c);
    }
  }
  if (local_20 == *(int *)(in_GS_OFFSET + 0x14)) {
    return param_3;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}

