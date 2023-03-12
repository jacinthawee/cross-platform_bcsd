
char * DES_fcrypt(char *buf,char *salt,char *ret)

{
  char cVar1;
  byte bVar2;
  undefined *puVar3;
  uint uVar4;
  uint uVar5;
  char cVar6;
  undefined4 uVar7;
  int iVar8;
  int iVar9;
  int iVar10;
  char *pcVar11;
  uint uVar12;
  char *pcVar13;
  uint uVar14;
  uint uVar15;
  undefined *puVar16;
  char *unaff_s0;
  undefined *unaff_s1;
  DES_key_schedule *unaff_s2;
  int unaff_s3;
  int unaff_s4;
  int iVar17;
  code *unaff_retaddr;
  undefined auStackX_0 [16];
  
  pcVar11 = ret;
code_r0x004dd740:
  pcVar13 = pcVar11;
  puVar3 = PTR___stack_chk_guard_006a9ae8;
  *(undefined **)((int)register0x00000074 + -0x14) = unaff_s1;
  *(char **)((int)register0x00000074 + -0x18) = unaff_s0;
  *(code **)((int)register0x00000074 + -4) = unaff_retaddr;
  *(int *)((int)register0x00000074 + -8) = unaff_s4;
  *(int *)((int)register0x00000074 + -0xc) = unaff_s3;
  *(DES_key_schedule **)((int)register0x00000074 + -0x10) = unaff_s2;
  *(undefined **)((int)register0x00000074 + -0xc0) = &_gp;
  cVar6 = *salt;
  *(undefined4 *)((int)register0x00000074 + -0x1c) = *(undefined4 *)PTR___stack_chk_guard_006a9ae8;
  unaff_s3 = 0x30;
  if (cVar6 == 0) {
    cVar6 = 'A';
  }
  else {
    unaff_s3 = (uint)(byte)(&con_salt)[cVar6] << 2;
  }
  *pcVar13 = cVar6;
  cVar6 = salt[1];
  unaff_s4 = 0x300;
  if (cVar6 == 0) {
    cVar6 = 'A';
  }
  else {
    unaff_s4 = (uint)(byte)(&con_salt)[cVar6] << 6;
  }
  pcVar13[1] = cVar6;
  if (*buf == '\0') {
    iVar8 = 0;
  }
  else {
    cVar6 = buf[1];
    *(char *)((int)register0x00000074 + -0x30) = *buf << 1;
    if (cVar6 == '\0') {
      iVar8 = 1;
    }
    else {
      cVar1 = buf[2];
      *(char *)((int)register0x00000074 + -0x2f) = cVar6 << 1;
      if (cVar1 == '\0') {
        iVar8 = 2;
      }
      else {
        cVar6 = buf[3];
        *(char *)((int)register0x00000074 + -0x2e) = cVar1 << 1;
        if (cVar6 == '\0') {
          iVar8 = 3;
        }
        else {
          cVar1 = buf[4];
          *(char *)((int)register0x00000074 + -0x2d) = cVar6 << 1;
          if (cVar1 == '\0') {
            iVar8 = 4;
          }
          else {
            cVar6 = buf[5];
            *(char *)((int)register0x00000074 + -0x2c) = cVar1 << 1;
            if (cVar6 == '\0') {
              iVar8 = 5;
            }
            else {
              cVar1 = buf[6];
              *(char *)((int)register0x00000074 + -0x2b) = cVar6 << 1;
              if (cVar1 == '\0') {
                iVar8 = 6;
              }
              else {
                cVar6 = buf[7];
                *(char *)((int)register0x00000074 + -0x2a) = cVar1 << 1;
                if (cVar6 != '\0') {
                  *(char *)((int)register0x00000074 + -0x29) = cVar6 << 1;
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
  uVar4 = *(uint *)((int)register0x00000074 + -0xb8);
  salt = pcVar13 + 2;
  uVar7 = *(undefined4 *)((int)register0x00000074 + -0xb4);
  iVar17 = *(int *)((int)register0x00000074 + -0xc0);
  *(undefined *)((int)register0x00000074 + -0x20) = 0;
  *(char *)((int)register0x00000074 + -0x24) = (char)uVar7;
  *(char *)((int)register0x00000074 + -0x26) = (char)(uVar4 >> 0x10);
  *(char *)((int)register0x00000074 + -0x27) = (char)(uVar4 >> 8);
  *(char *)((int)register0x00000074 + -0x23) = (char)((uint)uVar7 >> 8);
  uVar5 = uVar4 & 0xff;
  *(char *)((int)register0x00000074 + -0x21) = (char)((uint)uVar7 >> 0x18);
  *(char *)((int)register0x00000074 + -0x25) = (char)(uVar4 >> 0x18);
  uVar14 = 0x40;
  *(char *)((int)register0x00000074 + -0x22) = (char)((uint)uVar7 >> 0x10);
  *(char *)((int)register0x00000074 + -0x28) = (char)uVar5;
  iVar8 = 0;
  uVar4 = (uint)((uVar4 & 0x80) != 0);
LAB_004dd9c0:
  uVar4 = uVar4 << 1;
  iVar9 = iVar8;
  if ((uVar14 & uVar5) != 0) {
    uVar14 = uVar14 >> 1;
    goto LAB_004ddb34;
  }
  uVar14 = uVar14 >> 1;
  if (uVar14 != 0) goto LAB_004ddb3c;
LAB_004dd9dc:
  iVar10 = iVar9 + 1;
  uVar5 = uVar4 << 1;
  puVar16 = (undefined *)((int)register0x00000074 + iVar9 + -0x17);
  if ((puVar16[-0x10] & 0x80) != 0) {
    uVar12 = 0x40;
    goto LAB_004ddae8;
  }
  uVar5 = uVar4 << 2;
  uVar14 = 0x20;
  if ((puVar16[-0x10] & 0x40) == 0) goto LAB_004dda14;
LAB_004ddb14:
  uVar5 = uVar5 | 1;
  if (uVar14 != 0) goto LAB_004ddb1c;
LAB_004dda1c:
  iVar8 = iVar10 + 1;
  uVar4 = uVar5 << 1;
  puVar16 = (undefined *)((int)register0x00000074 + iVar10 + -0x17);
  if ((puVar16[-0x10] & 0x80) != 0) {
    uVar12 = 0x40;
    goto LAB_004ddab4;
  }
  uVar4 = uVar5 << 2;
  uVar15 = 0x20;
  if ((puVar16[-0x10] & 0x40) == 0) goto LAB_004dda58;
LAB_004ddad8:
  uVar4 = uVar4 | 1;
LAB_004dda58:
  if (uVar15 != 0) goto LAB_004dd990;
  iVar8 = iVar8 + 1;
  uVar15 = 0x80;
  *salt = cov_2char[uVar4];
  do {
    salt = salt + 1;
    if (salt == pcVar13 + 0xd) {
      buf = *(char **)((int)register0x00000074 + -0x1c);
      pcVar11 = *(char **)puVar3;
      pcVar13[0xd] = '\0';
      if (buf == pcVar11) {
        return pcVar13;
      }
      unaff_retaddr = DES_crypt;
      (**(code **)(iVar17 + -0x5330))();
      pcVar11 = buff_6268;
      unaff_s0 = pcVar13;
      unaff_s1 = puVar3;
      register0x00000074 = (BADSPACEBASE *)((int)register0x00000074 + -0xd0);
      goto code_r0x004dd740;
    }
    uVar14 = (uVar15 << 0x17) >> 0x18;
    uVar5 = (uint)*(byte *)((int)register0x00000074 + iVar8 + -0x28);
    uVar4 = (uint)((uVar15 & uVar5) != 0);
    if (uVar14 != 0) goto LAB_004dd9c0;
    iVar9 = iVar8 + 1;
    uVar4 = uVar4 << 1;
    puVar16 = (undefined *)((int)register0x00000074 + iVar8 + -0x17);
    bVar2 = puVar16[-0x10];
    if ((bVar2 & 0x80) == 0) {
      uVar12 = 0x20;
      uVar14 = 0x40;
    }
    else {
      uVar14 = 0x40;
LAB_004ddb34:
      uVar4 = uVar4 | 1;
      if (uVar14 == 0) goto LAB_004dd9dc;
LAB_004ddb3c:
      puVar16 = (undefined *)((int)register0x00000074 + iVar9 + -0x18);
      uVar12 = (uVar14 << 0x17) >> 0x18;
      bVar2 = puVar16[-0x10];
    }
    uVar5 = uVar4 << 1;
    iVar10 = iVar9;
    if ((uVar14 & bVar2) == 0) {
      if (uVar12 != 0) goto LAB_004ddaf4;
LAB_004dd92c:
      uVar5 = uVar5 << 1;
      puVar16 = (undefined *)((int)register0x00000074 + iVar10 + -0x17);
      bVar2 = puVar16[-0x10];
      if ((bVar2 & 0x80) != 0) {
        uVar14 = 0x40;
        iVar10 = iVar10 + 1;
        goto LAB_004ddb14;
      }
      uVar12 = 0x20;
      uVar14 = 0x40;
      iVar10 = iVar10 + 1;
    }
    else {
LAB_004ddae8:
      uVar5 = uVar5 | 1;
      if (uVar12 == 0) goto LAB_004dd92c;
LAB_004ddaf4:
      uVar5 = uVar5 << 1;
      uVar14 = uVar12 >> 1;
      if ((uVar12 & (byte)puVar16[-0x10]) != 0) goto LAB_004ddb14;
LAB_004dda14:
      if (uVar14 == 0) goto LAB_004dda1c;
LAB_004ddb1c:
      bVar2 = puVar16[-0x10];
      uVar12 = uVar14 >> 1;
    }
    uVar4 = uVar5 << 1;
    iVar8 = iVar10;
    if ((uVar14 & bVar2) != 0) {
LAB_004ddab4:
      uVar4 = uVar4 | 1;
    }
    if (uVar12 != 0) {
      uVar4 = uVar4 << 1;
      uVar15 = uVar12 >> 1;
      if ((uVar12 & (byte)puVar16[-0x10]) != 0) goto LAB_004ddad8;
      goto LAB_004dda58;
    }
    uVar4 = uVar4 << 1;
    if ((*(byte *)((int)register0x00000074 + iVar8 + -0x27) & 0x80) != 0) break;
    uVar15 = 0x40;
    iVar8 = iVar8 + 1;
LAB_004dd990:
    *salt = cov_2char[uVar4];
  } while( true );
  uVar4 = uVar4 | 1;
  uVar15 = 0x40;
  iVar8 = iVar8 + 1;
  goto LAB_004dda58;
}

