
/* WARNING: Could not reconcile some variable overlaps */

char * DES_fcrypt(char *buf,char *salt,char *ret)

{
  undefined4 *puVar1;
  uint uVar2;
  int iVar3;
  uint uVar4;
  char cVar5;
  byte bVar6;
  byte bVar7;
  byte bVar8;
  int iVar9;
  int iVar10;
  char *pcVar11;
  uint uVar12;
  int in_GS_OFFSET;
  bool bVar13;
  byte local_c6;
  byte local_c5;
  uint local_bc;
  undefined4 local_b8;
  DES_key_schedule local_b4;
  undefined4 local_31;
  undefined4 local_2d;
  byte abStack_29 [5];
  undefined local_24;
  undefined local_23;
  undefined local_22;
  undefined local_21;
  int local_20;
  
  cVar5 = *salt;
  local_20 = *(int *)(in_GS_OFFSET + 0x14);
  if (cVar5 == '\0') {
    iVar9 = 0x30;
    cVar5 = 'A';
  }
  else {
    iVar9 = (uint)(byte)(&con_salt)[cVar5] << 2;
  }
  *ret = cVar5;
  cVar5 = salt[1];
  if (cVar5 == '\0') {
    iVar10 = 0x300;
    cVar5 = 'A';
  }
  else {
    iVar10 = (uint)(byte)(&con_salt)[cVar5] << 6;
  }
  ret[1] = cVar5;
  if (*buf == '\0') {
    iVar3 = 0;
  }
  else {
    local_31._0_1_ = *buf * '\x02';
    if (buf[1] == '\0') {
      iVar3 = 1;
    }
    else {
      local_31._1_1_ = buf[1] * '\x02';
      if (buf[2] == '\0') {
        iVar3 = 2;
      }
      else {
        local_31._2_1_ = buf[2] * '\x02';
        if (buf[3] == '\0') {
          iVar3 = 3;
        }
        else {
          local_31._3_1_ = buf[3] * '\x02';
          if (buf[4] == '\0') {
            iVar3 = 4;
          }
          else {
            local_2d._0_1_ = buf[4] * '\x02';
            if (buf[5] == '\0') {
              iVar3 = 5;
            }
            else {
              local_2d._1_1_ = buf[5] * '\x02';
              if (buf[6] == '\0') {
                iVar3 = 6;
              }
              else {
                local_2d._2_1_ = buf[6] * '\x02';
                if (buf[7] != '\0') {
                  local_2d._3_1_ = buf[7] * '\x02';
                  goto LAB_080e6f6f;
                }
                iVar3 = 7;
              }
            }
          }
        }
      }
    }
  }
  uVar4 = 8 - iVar3;
  puVar1 = (undefined4 *)((int)&local_31 + iVar3);
  if (uVar4 < 4) {
    if ((uVar4 != 0) && (*(undefined *)puVar1 = 0, (uVar4 & 2) != 0)) {
      *(undefined2 *)((int)&local_31 + uVar4 + iVar3 + -2) = 0;
    }
  }
  else {
    *puVar1 = 0;
    *(undefined4 *)((int)&local_31 + uVar4 + iVar3 + -4) = 0;
    uVar12 = (int)&local_31 + iVar3 + 4 & 0xfffffffc;
    uVar4 = (uint)((int)puVar1 + (uVar4 - uVar12)) & 0xfffffffc;
    if (3 < uVar4) {
      uVar2 = 0;
      do {
        *(undefined4 *)(uVar12 + uVar2) = 0;
        uVar2 = uVar2 + 4;
      } while (uVar2 < uVar4);
    }
  }
LAB_080e6f6f:
  local_c5 = 0x80;
  DES_set_key_unchecked((const_DES_cblock *)&local_31,&local_b4);
  fcrypt_body(&local_bc,&local_b4,iVar9,iVar10);
  local_21 = 0;
  abStack_29[0] = (char)local_bc;
  abStack_29[1] = (char)(local_bc >> 8);
  abStack_29[3] = (char)(local_bc >> 0x18);
  abStack_29[2] = (char)(local_bc >> 0x10);
  abStack_29[4] = (char)local_b8;
  local_24 = (char)((uint)local_b8 >> 8);
  local_22 = (char)((uint)local_b8 >> 0x18);
  local_23 = (char)((uint)local_b8 >> 0x10);
  iVar9 = 0;
  pcVar11 = ret + 2;
  do {
    bVar13 = (local_c5 & (byte)local_bc) != 0;
    if (local_c5 >> 1 == 0) {
      iVar10 = iVar9 + 1;
      local_c6 = bVar13 * '\x02';
      bVar8 = *(byte *)((int)&local_31 + iVar9 + 9);
      if ((char)bVar8 < '\0') {
        local_c5 = 0x40;
        goto LAB_080e71a3;
      }
      bVar7 = 0x20;
      local_c5 = 0x40;
LAB_080e7030:
      local_c6 = local_c6 * '\x02';
      if ((local_c5 & bVar8) != 0) {
LAB_080e7039:
        local_c6 = local_c6 | 1;
      }
      if (bVar7 != 0) {
        bVar6 = bVar7 >> 1;
        iVar3 = iVar10;
        goto LAB_080e7124;
      }
      iVar3 = iVar10 + 1;
      local_c6 = local_c6 * '\x02';
      bVar8 = *(byte *)((int)&local_31 + iVar10 + 9);
      if ((char)bVar8 < '\0') {
        bVar6 = 0x40;
        goto LAB_080e7132;
      }
      bVar7 = 0x20;
      bVar6 = 0x40;
LAB_080e706b:
      local_c6 = local_c6 * '\x02';
      if ((bVar6 & bVar8) != 0) {
LAB_080e7079:
        local_c6 = local_c6 | 1;
      }
      if (bVar7 != 0) {
        local_c5 = bVar7 >> 1;
        goto LAB_080e716a;
      }
      iVar9 = iVar3 + 1;
      local_c5 = 0x40;
      local_c6 = local_c6 * '\x02';
      if (*(char *)((int)&local_31 + iVar3 + 9) < '\0') {
        local_c5 = 0x40;
        iVar3 = iVar9;
        goto LAB_080e70ab;
      }
    }
    else {
      local_c6 = bVar13 * '\x02';
      if ((byte)(local_c5 >> 1 & (byte)local_bc) == 0) {
        local_c5 = local_c5 >> 2;
      }
      else {
        local_c5 = local_c5 >> 2;
        iVar10 = iVar9;
LAB_080e71a3:
        local_c6 = bVar13 * '\x02' | 1;
        iVar9 = iVar10;
      }
      if (local_c5 != 0) {
        bVar8 = *(byte *)((int)&local_31 + iVar9 + 8);
        bVar7 = local_c5 >> 1;
        iVar10 = iVar9;
        goto LAB_080e7030;
      }
      iVar10 = iVar9 + 1;
      local_c6 = local_c6 * '\x02';
      bVar8 = *(byte *)((int)&local_31 + iVar9 + 9);
      if ((char)bVar8 < '\0') {
        bVar7 = 0x40;
        goto LAB_080e7039;
      }
      bVar6 = 0x20;
      bVar7 = 0x40;
      iVar3 = iVar10;
LAB_080e7124:
      local_c6 = local_c6 * '\x02';
      iVar9 = iVar3;
      if ((bVar7 & bVar8) != 0) {
LAB_080e7132:
        local_c6 = local_c6 | 1;
        iVar9 = iVar3;
      }
      if (bVar6 != 0) {
        bVar7 = bVar6 >> 1;
        iVar3 = iVar9;
        goto LAB_080e706b;
      }
      iVar3 = iVar9 + 1;
      bVar8 = *(byte *)((int)&local_31 + iVar9 + 9);
      local_c6 = local_c6 * '\x02';
      if ((char)bVar8 < '\0') {
        bVar7 = 0x40;
        goto LAB_080e7079;
      }
      local_c5 = 0x20;
      bVar7 = 0x40;
LAB_080e716a:
      local_c6 = local_c6 * '\x02';
      iVar9 = iVar3;
      if ((bVar7 & bVar8) != 0) {
LAB_080e70ab:
        local_c6 = local_c6 | 1;
        iVar9 = iVar3;
      }
      if (local_c5 == 0) {
        iVar9 = iVar9 + 1;
        local_c5 = 0x80;
      }
    }
    *pcVar11 = cov_2char[local_c6];
    if (pcVar11 + 1 == ret + 0xd) {
      iVar9 = *(int *)(in_GS_OFFSET + 0x14);
      ret[0xd] = '\0';
      if (local_20 == iVar9) {
        return ret;
      }
                    /* WARNING: Subroutine does not return */
      __stack_chk_fail();
    }
    local_bc = (uint)*(byte *)((int)&local_31 + iVar9 + 8);
    pcVar11 = pcVar11 + 1;
  } while( true );
}

