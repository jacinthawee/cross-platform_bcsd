
void dgram_ctrl(int param_1,undefined4 param_2,size_t param_3,undefined4 *param_4)

{
  short sVar1;
  int iVar2;
  undefined4 uVar3;
  uint uVar4;
  undefined4 uVar5;
  undefined4 uVar6;
  undefined4 uVar7;
  size_t sVar8;
  undefined4 *__src;
  uint local_4c;
  socklen_t local_48;
  size_t local_44;
  sockaddr local_40;
  undefined4 local_30;
  undefined4 local_2c;
  undefined4 local_28;
  int local_24;
  
  __src = *(undefined4 **)(param_1 + 0x20);
  local_4c = 0;
  local_24 = __TMC_END__;
  switch(param_2) {
  case 8:
    param_3 = *(size_t *)(param_1 + 0x10);
    break;
  case 9:
    *(size_t *)(param_1 + 0x10) = param_3;
    param_3 = 1;
    break;
  default:
    goto switchD_000a4f2c_caseD_a;
  case 0xb:
  case 0xc:
    goto switchD_000a4f2c_caseD_b;
  case 0x1f:
  case 0x2c:
    if ((*(short *)param_4 != 2) && (*(short *)param_4 == 10)) {
      uVar5 = *param_4;
LAB_000a511a:
      param_3 = 1;
      uVar3 = param_4[1];
      uVar6 = param_4[2];
      uVar7 = param_4[3];
      *__src = uVar5;
      __src[1] = uVar3;
      __src[2] = uVar6;
      __src[3] = uVar7;
      uVar5 = param_4[5];
      uVar3 = param_4[6];
      __src[4] = param_4[4];
      __src[5] = uVar5;
      __src[6] = uVar3;
      break;
    }
    uVar5 = *param_4;
    goto LAB_000a5004;
  case 0x20:
    if (param_4 == (undefined4 *)0x0) {
      __src[7] = 0;
      memset(__src,0,0x1c);
      param_3 = 1;
      break;
    }
    sVar1 = *(short *)param_4;
    __src[7] = 1;
    uVar5 = *param_4;
    if ((sVar1 != 2) && (sVar1 == 10)) goto LAB_000a511a;
LAB_000a5004:
    param_3 = 1;
    uVar3 = param_4[1];
    uVar6 = param_4[2];
    uVar7 = param_4[3];
    *__src = uVar5;
    __src[1] = uVar3;
    __src[2] = uVar6;
    __src[3] = uVar7;
    break;
  case 0x21:
    iVar2 = setsockopt(*(int *)(param_1 + 0x1c),1,0x14,param_4,8);
    goto joined_r0x000a503c;
  case 0x22:
    local_44 = 8;
    iVar2 = getsockopt(*(int *)(param_1 + 0x1c),1,0x14,param_4,&local_44);
    param_3 = local_44;
    goto joined_r0x000a5180;
  case 0x23:
    iVar2 = setsockopt(*(int *)(param_1 + 0x1c),1,0x15,param_4,8);
joined_r0x000a503c:
    if (iVar2 < 0) {
      perror("setsockopt");
      param_3 = 0xffffffff;
    }
    else {
switchD_000a4f2c_caseD_b:
      param_3 = 1;
    }
    break;
  case 0x24:
    local_44 = 8;
    iVar2 = getsockopt(*(int *)(param_1 + 0x1c),1,0x15,param_4,&local_44);
    param_3 = local_44;
joined_r0x000a5180:
    local_44 = param_3;
    if (iVar2 < 0) {
      perror("getsockopt");
      param_3 = 0xffffffff;
    }
    break;
  case 0x25:
  case 0x26:
    if (__src[8] == 0xb) {
LAB_000a50de:
      param_3 = 1;
      __src[8] = 0;
      break;
    }
    goto switchD_000a4f2c_caseD_a;
  case 0x27:
    local_40._0_4_ = 0;
    local_44 = 0x1c;
    local_40.sa_data._2_4_ = 0;
    local_40.sa_data._6_4_ = 0;
    local_40.sa_data._10_4_ = 0;
    local_30 = 0;
    local_2c = 0;
    local_28 = 0;
    iVar2 = getsockname(*(int *)(param_1 + 0x1c),&local_40,&local_44);
    if (-1 < iVar2) {
      uVar4 = local_40._0_4_ & 0xffff;
      if (uVar4 == 2) {
        local_4c = uVar4;
        iVar2 = setsockopt(*(int *)(param_1 + 0x1c),0,10,&local_4c,4);
      }
      else {
        if (uVar4 != 10) goto LAB_000a504a;
        local_4c = 2;
        iVar2 = setsockopt(*(int *)(param_1 + 0x1c),0x29,0x17,&local_4c,4);
      }
      if (iVar2 < 0) {
        perror("setsockopt");
      }
      goto LAB_000a504a;
    }
    goto switchD_000a4f2c_caseD_a;
  case 0x28:
LAB_000a504a:
    local_40._0_4_ = 0;
    local_44 = 0x1c;
    local_40.sa_data._2_4_ = 0;
    local_40.sa_data._6_4_ = 0;
    local_40.sa_data._10_4_ = 0;
    local_30 = 0;
    local_2c = 0;
    local_28 = 0;
    iVar2 = getsockname(*(int *)(param_1 + 0x1c),&local_40,&local_44);
    if (-1 < iVar2) {
      local_48 = 4;
      if ((local_40._0_4_ & 0xffff) == 2) {
        iVar2 = getsockopt(*(int *)(param_1 + 0x1c),0,0xe,&local_4c,&local_48);
        if ((-1 < iVar2) && (-1 < (int)local_4c)) {
          param_3 = local_4c - 0x1c;
          __src[9] = param_3;
          break;
        }
      }
      else {
        if ((local_40._0_4_ & 0xffff) != 10) {
          param_3 = 0;
          break;
        }
        iVar2 = getsockopt(*(int *)(param_1 + 0x1c),0x29,0x18,&local_4c,&local_48);
        if ((-1 < iVar2) && (-1 < (int)local_4c)) {
          param_3 = local_4c - 0x30;
          __src[9] = param_3;
          break;
        }
      }
    }
    goto switchD_000a4f2c_caseD_a;
  case 0x29:
    param_3 = __src[9];
    break;
  case 0x2a:
    __src[9] = param_3;
    break;
  case 0x2b:
    if (__src[8] == 0x5a) goto LAB_000a50de;
switchD_000a4f2c_caseD_a:
    param_3 = 0;
    break;
  case 0x2d:
    param_3 = 1;
    uVar5 = param_4[1];
    __src[10] = *param_4;
    __src[0xb] = uVar5;
    break;
  case 0x2e:
    uVar4 = count_leading_zeroes(param_3);
    uVar4 = uVar4 >> 5;
    if (*(short *)__src == 10) {
      sVar8 = 0x1c;
    }
    else {
      sVar8 = 0x10;
    }
    if ((int)sVar8 < (int)param_3) {
      uVar4 = uVar4 | 1;
    }
    if (uVar4 == 0) {
      sVar8 = param_3;
    }
    param_3 = sVar8;
    memcpy(param_4,__src,param_3);
    break;
  case 0x2f:
    if (*(short *)__src == 10) {
      if ((__src[2] == 0) && (__src[3] == 0)) {
        if (__src[4] == -0x10000) {
          param_3 = 0x224;
        }
        else {
          param_3 = 0x4d0;
        }
      }
      else {
        param_3 = 0x4d0;
      }
    }
    else {
      param_3 = 0x224;
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
    uVar5 = *param_4;
    *(size_t *)(param_1 + 0x10) = param_3;
    param_3 = 1;
    *(undefined4 *)(param_1 + 0xc) = 1;
    *(undefined4 *)(param_1 + 0x1c) = uVar5;
    break;
  case 0x69:
    param_3 = 0xffffffff;
    if (*(int *)(param_1 + 0xc) != 0) {
      if (param_4 != (undefined4 *)0x0) {
        *param_4 = *(undefined4 *)(param_1 + 0x1c);
      }
      param_3 = *(size_t *)(param_1 + 0x1c);
    }
  }
  if (local_24 == __TMC_END__) {
    return;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail(param_3);
}

