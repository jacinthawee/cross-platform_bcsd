
char * DES_fcrypt(char *buf,char *salt,char *ret)

{
  byte bVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  uint uVar5;
  byte bVar6;
  uint uVar7;
  uint uVar8;
  uint uVar9;
  uint uVar10;
  int iVar11;
  uint local_c0;
  undefined4 uStack_bc;
  DES_key_schedule DStack_b8;
  uchar local_38 [4];
  uchar local_34;
  uchar local_33;
  uchar local_32;
  uchar local_31;
  byte local_30 [5];
  undefined local_2b;
  undefined local_2a;
  undefined local_29;
  undefined local_28;
  int local_24;
  
  bVar6 = *salt;
  uVar7 = (uint)bVar6;
  local_24 = __TMC_END__;
  if (uVar7 == 0) {
    uVar7 = 0x41;
    bVar6 = 0x41;
  }
  *ret = bVar6;
  uVar8 = (uint)(byte)salt[1];
  bVar6 = (&con_salt)[uVar7];
  if (uVar8 == 0) {
    uVar8 = 0x41;
  }
  ret[1] = (char)uVar8;
  bVar1 = (&con_salt)[uVar8];
  uVar7 = (uint)(byte)*buf;
  if (uVar7 != 0) {
    local_38[0] = *buf << 1;
    if (buf[1] == '\0') {
      uVar7 = 1;
    }
    else {
      local_38[1] = buf[1] << 1;
      if (buf[2] == '\0') {
        uVar7 = 2;
      }
      else {
        local_38[2] = buf[2] << 1;
        if (buf[3] == '\0') {
          uVar7 = 3;
        }
        else {
          local_38[3] = buf[3] << 1;
          if (buf[4] == '\0') {
            uVar7 = 4;
          }
          else {
            local_34 = buf[4] << 1;
            if (buf[5] == '\0') {
              uVar7 = 5;
            }
            else {
              local_33 = buf[5] << 1;
              if (buf[6] == '\0') {
                uVar7 = 6;
              }
              else {
                local_32 = buf[6] << 1;
                uVar7 = 7;
                if (buf[7] != '\0') {
                  local_31 = buf[7] << 1;
                  goto LAB_0007d52e;
                }
              }
            }
          }
        }
      }
    }
  }
  memset(local_38 + uVar7,0,8 - uVar7);
LAB_0007d52e:
  DES_set_key_unchecked((const_DES_cblock *)local_38,&DStack_b8);
  fcrypt_body(&local_c0,&DStack_b8,(uint)bVar6 << 2,(uint)bVar1 << 6);
  local_28 = 0;
  uVar9 = local_c0 & 0xff;
  local_30[1] = (char)(local_c0 >> 8);
  local_30[2] = (char)(local_c0 >> 0x10);
  local_30[4] = (char)uStack_bc;
  local_30[3] = (char)(local_c0 >> 0x18);
  uVar7 = uVar9 >> 7;
  local_2b = (char)((uint)uStack_bc >> 8);
  local_30[0] = (byte)uVar9;
  local_2a = (char)((uint)uStack_bc >> 0x10);
  iVar11 = 2;
  local_29 = (char)((uint)uStack_bc >> 0x18);
  uVar8 = 0x40;
  iVar3 = 0;
  while( true ) {
    uVar7 = uVar7 << 1;
    if ((uVar8 & uVar9) != 0) {
      uVar7 = uVar7 | 1;
    }
    uVar10 = uVar8 >> 1;
    if (uVar10 == 0) {
      iVar2 = iVar3 + 1;
      uVar8 = 0x40;
      uVar9 = (uint)local_30[iVar3 + 1];
      uVar10 = 0x80;
    }
    else {
      uVar8 = uVar8 >> 2;
      iVar2 = iVar3;
    }
    uVar7 = uVar7 << 1;
    uVar5 = uVar8 >> 1;
    if ((uVar10 & uVar9) != 0) {
      uVar7 = uVar7 | 1;
    }
    iVar3 = iVar2;
    if (uVar8 == 0) {
      iVar3 = iVar2 + 1;
      uVar5 = 0x40;
      uVar8 = 0x80;
      uVar9 = (uint)local_30[iVar2 + 1];
    }
    uVar10 = uVar5 >> 1;
    uVar7 = uVar7 << 1;
    if ((uVar9 & uVar8) != 0) {
      uVar7 = uVar7 | 1;
    }
    iVar2 = iVar3;
    if (uVar5 == 0) {
      iVar2 = iVar3 + 1;
      uVar10 = 0x40;
      uVar5 = 0x80;
      uVar9 = (uint)local_30[iVar3 + 1];
    }
    uVar8 = uVar10 >> 1;
    uVar7 = uVar7 << 1;
    if ((uVar9 & uVar5) != 0) {
      uVar7 = uVar7 | 1;
    }
    iVar4 = iVar2;
    if (uVar10 == 0) {
      iVar4 = iVar2 + 1;
      uVar8 = 0x40;
      uVar10 = 0x80;
      uVar9 = (uint)local_30[iVar2 + 1];
    }
    uVar7 = uVar7 << 1;
    if ((uVar9 & uVar10) != 0) {
      uVar7 = uVar7 | 1;
    }
    if (uVar8 == 0) {
      iVar4 = iVar4 + 1;
      uVar8 = 0x80;
    }
    ret[iVar11] = " !\"#$% !\"#$%&\'()*+,-./0123456789:;<=>?@ABCD./0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyzAES part of OpenSSL 1.0.1f 6 Jan 2014"
                  [uVar7 + 0x2b];
    iVar3 = __TMC_END__;
    iVar11 = iVar11 + 1;
    if (iVar11 == 0xd) break;
    uVar9 = (uint)local_30[iVar4];
    uVar7 = (uint)((uVar9 & uVar8) != 0);
    uVar8 = uVar8 >> 1;
    iVar3 = iVar4;
    if (uVar8 == 0) {
      iVar3 = iVar4 + 1;
      uVar8 = 0x80;
      uVar9 = (uint)local_30[iVar4 + 1];
    }
  }
  ret[0xd] = '\0';
  if (local_24 != iVar3) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return ret;
}

