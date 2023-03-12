
char * DES_crypt(char *buf,char *salt)

{
  char cVar1;
  char cVar2;
  byte bVar3;
  undefined *puVar4;
  uint uVar5;
  uint uVar6;
  undefined4 uVar7;
  int iVar8;
  int iVar9;
  int iVar10;
  uint uVar11;
  uint uVar12;
  uint uVar13;
  undefined *puVar14;
  undefined1 *unaff_s0;
  undefined *unaff_s1;
  DES_key_schedule *unaff_s2;
  int unaff_s3;
  int unaff_s4;
  int iVar15;
  code *unaff_retaddr;
  undefined auStackX_0 [16];
  
DES_fcrypt:
  puVar4 = PTR___stack_chk_guard_006a9ae8;
  *(undefined **)((int)register0x00000074 + -0x14) = unaff_s1;
  *(undefined1 **)((int)register0x00000074 + -0x18) = unaff_s0;
  *(code **)((int)register0x00000074 + -4) = unaff_retaddr;
  *(int *)((int)register0x00000074 + -8) = unaff_s4;
  *(int *)((int)register0x00000074 + -0xc) = unaff_s3;
  *(DES_key_schedule **)((int)register0x00000074 + -0x10) = unaff_s2;
  *(undefined **)((int)register0x00000074 + -0xc0) = &_gp;
  buff_6268[0] = *salt;
  *(undefined4 *)((int)register0x00000074 + -0x1c) = *(undefined4 *)PTR___stack_chk_guard_006a9ae8;
  unaff_s3 = 0x30;
  if (buff_6268[0] == 0) {
    buff_6268[0] = 'A';
  }
  else {
    unaff_s3 = (uint)(byte)(&con_salt)[buff_6268[0]] << 2;
  }
  buff_6268[1] = salt[1];
  unaff_s4 = 0x300;
  if (buff_6268[1] == 0) {
    buff_6268[1] = 'A';
  }
  else {
    unaff_s4 = (uint)(byte)(&con_salt)[buff_6268[1]] << 6;
  }
  if (*buf == '\0') {
    iVar8 = 0;
  }
  else {
    cVar1 = buf[1];
    *(char *)((int)register0x00000074 + -0x30) = *buf << 1;
    if (cVar1 == '\0') {
      iVar8 = 1;
    }
    else {
      cVar2 = buf[2];
      *(char *)((int)register0x00000074 + -0x2f) = cVar1 << 1;
      if (cVar2 == '\0') {
        iVar8 = 2;
      }
      else {
        cVar1 = buf[3];
        *(char *)((int)register0x00000074 + -0x2e) = cVar2 << 1;
        if (cVar1 == '\0') {
          iVar8 = 3;
        }
        else {
          cVar2 = buf[4];
          *(char *)((int)register0x00000074 + -0x2d) = cVar1 << 1;
          if (cVar2 == '\0') {
            iVar8 = 4;
          }
          else {
            cVar1 = buf[5];
            *(char *)((int)register0x00000074 + -0x2c) = cVar2 << 1;
            if (cVar1 == '\0') {
              iVar8 = 5;
            }
            else {
              cVar2 = buf[6];
              *(char *)((int)register0x00000074 + -0x2b) = cVar1 << 1;
              if (cVar2 == '\0') {
                iVar8 = 6;
              }
              else {
                cVar1 = buf[7];
                *(char *)((int)register0x00000074 + -0x2a) = cVar2 << 1;
                if (cVar1 != '\0') {
                  *(char *)((int)register0x00000074 + -0x29) = cVar1 << 1;
                  goto LAB_004dd844;
                }
                iVar8 = 7;
              }
            }
          }
        }
      }
    }
  }
  (*(code *)PTR_memset_006a99f4)((undefined *)((int)register0x00000074 + iVar8 + -0x30),0,8 - iVar8)
  ;
LAB_004dd844:
  unaff_s2 = (DES_key_schedule *)((int)register0x00000074 + -0xb0);
  DES_set_key_unchecked((const_DES_cblock *)((int)register0x00000074 + -0x30),unaff_s2);
  (**(code **)(*(int *)((int)register0x00000074 + -0xc0) + -0x6914))
            ((undefined *)((int)register0x00000074 + -0xb8),unaff_s2,unaff_s3,unaff_s4);
  uVar5 = *(uint *)((int)register0x00000074 + -0xb8);
  salt = buff_6268 + 2;
  uVar7 = *(undefined4 *)((int)register0x00000074 + -0xb4);
  iVar15 = *(int *)((int)register0x00000074 + -0xc0);
  *(undefined *)((int)register0x00000074 + -0x20) = 0;
  *(char *)((int)register0x00000074 + -0x24) = (char)uVar7;
  *(char *)((int)register0x00000074 + -0x26) = (char)(uVar5 >> 0x10);
  *(char *)((int)register0x00000074 + -0x27) = (char)(uVar5 >> 8);
  *(char *)((int)register0x00000074 + -0x23) = (char)((uint)uVar7 >> 8);
  uVar6 = uVar5 & 0xff;
  *(char *)((int)register0x00000074 + -0x21) = (char)((uint)uVar7 >> 0x18);
  *(char *)((int)register0x00000074 + -0x25) = (char)(uVar5 >> 0x18);
  uVar12 = 0x40;
  *(char *)((int)register0x00000074 + -0x22) = (char)((uint)uVar7 >> 0x10);
  *(char *)((int)register0x00000074 + -0x28) = (char)uVar6;
  iVar8 = 0;
  uVar5 = (uint)((uVar5 & 0x80) != 0);
LAB_004dd9c0:
  uVar5 = uVar5 << 1;
  iVar9 = iVar8;
  if ((uVar12 & uVar6) != 0) {
    uVar12 = uVar12 >> 1;
    goto LAB_004ddb34;
  }
  uVar12 = uVar12 >> 1;
  if (uVar12 != 0) goto LAB_004ddb3c;
LAB_004dd9dc:
  iVar10 = iVar9 + 1;
  uVar6 = uVar5 << 1;
  puVar14 = (undefined *)((int)register0x00000074 + iVar9 + -0x17);
  if ((puVar14[-0x10] & 0x80) != 0) {
    uVar11 = 0x40;
    goto LAB_004ddae8;
  }
  uVar6 = uVar5 << 2;
  uVar12 = 0x20;
  if ((puVar14[-0x10] & 0x40) == 0) goto LAB_004dda14;
LAB_004ddb14:
  uVar6 = uVar6 | 1;
  if (uVar12 != 0) goto LAB_004ddb1c;
LAB_004dda1c:
  iVar8 = iVar10 + 1;
  uVar5 = uVar6 << 1;
  puVar14 = (undefined *)((int)register0x00000074 + iVar10 + -0x17);
  if ((puVar14[-0x10] & 0x80) != 0) {
    uVar11 = 0x40;
    goto LAB_004ddab4;
  }
  uVar5 = uVar6 << 2;
  uVar13 = 0x20;
  if ((puVar14[-0x10] & 0x40) == 0) goto LAB_004dda58;
LAB_004ddad8:
  uVar5 = uVar5 | 1;
LAB_004dda58:
  if (uVar13 != 0) goto LAB_004dd990;
  iVar8 = iVar8 + 1;
  uVar13 = 0x80;
  *salt = cov_2char[uVar5];
  do {
    salt = salt + 1;
    if (salt == buff_6268 + 0xd) {
      buf = *(char **)((int)register0x00000074 + -0x1c);
      buff_6268[13] = 0;
      if (buf == *(char **)puVar4) {
        return buff_6268;
      }
      unaff_retaddr = DES_crypt;
      (**(code **)(iVar15 + -0x5330))();
      unaff_s0 = buff_6268;
      unaff_s1 = puVar4;
      register0x00000074 = (BADSPACEBASE *)((int)register0x00000074 + -0xd0);
      goto DES_fcrypt;
    }
    uVar12 = (uVar13 << 0x17) >> 0x18;
    uVar6 = (uint)*(byte *)((int)register0x00000074 + iVar8 + -0x28);
    uVar5 = (uint)((uVar13 & uVar6) != 0);
    if (uVar12 != 0) goto LAB_004dd9c0;
    iVar9 = iVar8 + 1;
    uVar5 = uVar5 << 1;
    puVar14 = (undefined *)((int)register0x00000074 + iVar8 + -0x17);
    bVar3 = puVar14[-0x10];
    if ((bVar3 & 0x80) == 0) {
      uVar11 = 0x20;
      uVar12 = 0x40;
    }
    else {
      uVar12 = 0x40;
LAB_004ddb34:
      uVar5 = uVar5 | 1;
      if (uVar12 == 0) goto LAB_004dd9dc;
LAB_004ddb3c:
      puVar14 = (undefined *)((int)register0x00000074 + iVar9 + -0x18);
      uVar11 = (uVar12 << 0x17) >> 0x18;
      bVar3 = puVar14[-0x10];
    }
    uVar6 = uVar5 << 1;
    iVar10 = iVar9;
    if ((uVar12 & bVar3) == 0) {
      if (uVar11 != 0) goto LAB_004ddaf4;
LAB_004dd92c:
      uVar6 = uVar6 << 1;
      puVar14 = (undefined *)((int)register0x00000074 + iVar10 + -0x17);
      bVar3 = puVar14[-0x10];
      if ((bVar3 & 0x80) != 0) {
        uVar12 = 0x40;
        iVar10 = iVar10 + 1;
        goto LAB_004ddb14;
      }
      uVar11 = 0x20;
      uVar12 = 0x40;
      iVar10 = iVar10 + 1;
    }
    else {
LAB_004ddae8:
      uVar6 = uVar6 | 1;
      if (uVar11 == 0) goto LAB_004dd92c;
LAB_004ddaf4:
      uVar6 = uVar6 << 1;
      uVar12 = uVar11 >> 1;
      if ((uVar11 & (byte)puVar14[-0x10]) != 0) goto LAB_004ddb14;
LAB_004dda14:
      if (uVar12 == 0) goto LAB_004dda1c;
LAB_004ddb1c:
      bVar3 = puVar14[-0x10];
      uVar11 = uVar12 >> 1;
    }
    uVar5 = uVar6 << 1;
    iVar8 = iVar10;
    if ((uVar12 & bVar3) != 0) {
LAB_004ddab4:
      uVar5 = uVar5 | 1;
    }
    if (uVar11 != 0) {
      uVar5 = uVar5 << 1;
      uVar13 = uVar11 >> 1;
      if ((uVar11 & (byte)puVar14[-0x10]) != 0) goto LAB_004ddad8;
      goto LAB_004dda58;
    }
    uVar5 = uVar5 << 1;
    if ((*(byte *)((int)register0x00000074 + iVar8 + -0x27) & 0x80) != 0) break;
    uVar13 = 0x40;
    iVar8 = iVar8 + 1;
LAB_004dd990:
    *salt = cov_2char[uVar5];
  } while( true );
  uVar5 = uVar5 | 1;
  uVar13 = 0x40;
  iVar8 = iVar8 + 1;
  goto LAB_004dda58;
}

