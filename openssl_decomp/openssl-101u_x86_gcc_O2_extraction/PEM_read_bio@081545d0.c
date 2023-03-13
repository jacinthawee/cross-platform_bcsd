
int PEM_read_bio(BIO *bp,char **name,char **header,uchar **data,long *len)

{
  uint uVar1;
  uint *puVar2;
  byte bVar3;
  BUF_MEM *a;
  BUF_MEM *a_00;
  int iVar4;
  size_t sVar5;
  int iVar6;
  int iVar7;
  uint uVar8;
  char cVar9;
  char *pcVar10;
  uint uVar11;
  undefined4 *puVar12;
  char *pcVar13;
  byte *pbVar14;
  int in_GS_OFFSET;
  bool bVar15;
  bool bVar16;
  byte bVar17;
  BUF_MEM *local_1b0;
  int local_1ac;
  char *local_1a8;
  BUF_MEM *local_1a4;
  int local_188;
  int local_184;
  undefined local_180 [96];
  undefined4 local_120;
  char acStack_11b [4];
  char local_117 [245];
  undefined local_22;
  int local_20;
  
  bVar17 = 0;
  local_184 = 0;
  local_20 = *(int *)(in_GS_OFFSET + 0x14);
  a = BUF_MEM_new();
  a_00 = BUF_MEM_new();
  local_1a4 = BUF_MEM_new();
  if ((a == (BUF_MEM *)0x0 || a_00 == (BUF_MEM *)0x0) || (local_1a4 == (BUF_MEM *)0x0)) {
    BUF_MEM_free(a);
    BUF_MEM_free(a_00);
    BUF_MEM_free(local_1a4);
    ERR_put_error(9,0x6d,0x41,"pem_lib.c",0x2af);
    iVar4 = 0;
    goto LAB_08154745;
  }
  local_22 = 0;
  do {
    do {
      iVar4 = BIO_gets(bp,(char *)&local_120,0xfe);
      local_1b0 = a_00;
      if (iVar4 < 1) {
        ERR_put_error(9,0x6d,0x6c,"pem_lib.c",0x2b8);
        goto LAB_08154720;
      }
      do {
        bVar3 = *(byte *)((int)&local_120 + iVar4);
        bVar15 = bVar3 == 0x20;
        if (' ' < (char)bVar3) break;
        iVar4 = iVar4 + -1;
        bVar15 = iVar4 == -1;
      } while (!bVar15);
      *(undefined *)((int)&local_120 + iVar4 + 1) = 10;
      *(undefined *)((int)&local_120 + iVar4 + 2) = 0;
      iVar4 = 0xb;
      puVar12 = &local_120;
      pbVar14 = (byte *)"-----BEGIN ";
      do {
        if (iVar4 == 0) break;
        iVar4 = iVar4 + -1;
        bVar15 = *(byte *)puVar12 == *pbVar14;
        puVar12 = (undefined4 *)((int)puVar12 + (uint)bVar17 * -2 + 1);
        pbVar14 = pbVar14 + (uint)bVar17 * -2 + 1;
      } while (bVar15);
    } while (!bVar15);
    sVar5 = strlen(local_117 + 2);
    iVar4 = 6;
    bVar15 = &stack0x00000000 == (undefined *)0x1bc;
    pcVar10 = acStack_11b + sVar5;
    pcVar13 = "-----\n";
    do {
      if (iVar4 == 0) break;
      iVar4 = iVar4 + -1;
      bVar15 = *pcVar10 == *pcVar13;
      pcVar10 = pcVar10 + (uint)bVar17 * -2 + 1;
      pcVar13 = pcVar13 + (uint)bVar17 * -2 + 1;
    } while (bVar15);
  } while (!bVar15);
  iVar4 = BUF_MEM_grow(a,sVar5 + 9);
  if (iVar4 == 0) {
    iVar4 = 0x2c7;
  }
  else {
    memcpy(a->data,local_117 + 2,sVar5 - 6);
    a->data[sVar5 - 6] = '\0';
    iVar4 = BUF_MEM_grow(a_00,0x100);
    if (iVar4 == 0) {
      iVar4 = 0x2d1;
    }
    else {
      local_1ac = 0;
      *a_00->data = '\0';
      while (iVar4 = BIO_gets(bp,(char *)&local_120,0xfe), 0 < iVar4) {
        do {
          if (' ' < (char)*(byte *)((int)&local_120 + iVar4)) break;
          iVar4 = iVar4 + -1;
        } while (iVar4 != -1);
        *(undefined *)((int)&local_120 + iVar4 + 1) = 10;
        *(undefined *)((int)&local_120 + iVar4 + 2) = 0;
        if ((char)local_120 == '\n') break;
        iVar6 = local_1ac + iVar4 + 2U;
        iVar7 = BUF_MEM_grow(a_00,iVar6 + 9);
        bVar15 = iVar7 == 0;
        if (bVar15) {
          iVar4 = 0x2e2;
          goto LAB_0815470d;
        }
        iVar7 = 9;
        puVar12 = &local_120;
        pbVar14 = (byte *)"-----END ";
        do {
          if (iVar7 == 0) break;
          iVar7 = iVar7 + -1;
          bVar15 = *(byte *)puVar12 == *pbVar14;
          puVar12 = (undefined4 *)((int)puVar12 + (uint)bVar17 * -2 + 1);
          pbVar14 = pbVar14 + (uint)bVar17 * -2 + 1;
        } while (bVar15);
        if (bVar15) {
          local_184 = 0;
          iVar4 = BUF_MEM_grow(local_1a4,0x400);
          bVar15 = false;
          bVar16 = iVar4 == 0;
          if (bVar16) goto LAB_081548fe;
          iVar4 = 9;
          *local_1a4->data = '\0';
          local_184 = local_1ac;
          puVar12 = &local_120;
          pbVar14 = (byte *)"-----END ";
          goto code_r0x08154c0e;
        }
        memcpy(a_00->data + local_1ac,&local_120,iVar4 + 2U);
        a_00->data[iVar6] = '\0';
        local_1ac = iVar6;
      }
      local_184 = 0;
      iVar4 = BUF_MEM_grow(local_1a4,0x400);
      if (iVar4 != 0) {
        local_1a8 = "-----END ";
        *local_1a4->data = '\0';
        do {
          iVar4 = BIO_gets(bp,(char *)&local_120,0xfe);
          bVar15 = false;
          bVar16 = iVar4 == 0;
          if (iVar4 < 1) goto LAB_08154a37;
          do {
            pbVar14 = (byte *)((int)&local_120 + iVar4);
            bVar15 = *pbVar14 < 0x20;
            bVar3 = *pbVar14;
            bVar16 = bVar3 == 0x20;
            if (' ' < (char)bVar3) break;
            iVar4 = iVar4 + -1;
            bVar15 = iVar4 != -1;
            bVar16 = iVar4 == -1;
          } while (!bVar16);
          uVar1 = iVar4 + 2;
          *(undefined *)((int)&local_120 + iVar4 + 1) = 10;
          iVar6 = 9;
          *(undefined *)((int)&local_120 + iVar4 + 2) = 0;
          puVar12 = &local_120;
          pbVar14 = (byte *)local_1a8;
          do {
            if (iVar6 == 0) break;
            iVar6 = iVar6 + -1;
            bVar15 = *(byte *)puVar12 < *pbVar14;
            bVar16 = *(byte *)puVar12 == *pbVar14;
            puVar12 = (undefined4 *)((int)puVar12 + (uint)bVar17 * -2 + 1);
            pbVar14 = pbVar14 + (uint)bVar17 * -2 + 1;
          } while (bVar16);
          cVar9 = (!bVar15 && !bVar16) - bVar15;
          if ((cVar9 == '\0') || (0x41 < (int)uVar1)) goto LAB_08154a4f;
          iVar6 = BUF_MEM_grow_clean(local_1a4,local_184 + uVar1 + 9);
          if (iVar6 == 0) {
            iVar4 = 0x306;
            goto LAB_0815470d;
          }
          pcVar10 = local_1a4->data;
          puVar2 = (uint *)(pcVar10 + local_184);
          if (uVar1 < 4) {
            if (uVar1 != 0) {
              *(char *)puVar2 = (char)local_120;
              if ((uVar1 & 2) == 0) {
                pcVar10 = local_1a4->data;
              }
              else {
                *(undefined2 *)((int)puVar2 + iVar4) = *(undefined2 *)((int)&local_120 + iVar4);
                pcVar10 = local_1a4->data;
              }
            }
          }
          else {
            *puVar2 = local_120;
            *(undefined4 *)((int)puVar2 + iVar4 + -2) = *(undefined4 *)(local_180 + iVar4 + 0x5e);
            iVar4 = (int)puVar2 - ((uint)(puVar2 + 1) & 0xfffffffc);
            uVar8 = iVar4 + uVar1 & 0xfffffffc;
            if (3 < uVar8) {
              uVar11 = 0;
              do {
                *(undefined4 *)(((uint)(puVar2 + 1) & 0xfffffffc) + uVar11) =
                     *(undefined4 *)((int)&local_120 + (uVar11 - iVar4));
                uVar11 = uVar11 + 4;
              } while (uVar11 < uVar8);
            }
            pcVar10 = local_1a4->data;
          }
          pcVar10[local_184 + uVar1] = '\0';
          local_184 = local_184 + uVar1;
        } while (uVar1 == 0x41);
        local_120 = local_120 & 0xffffff00;
        iVar4 = BIO_gets(bp,(char *)&local_120,0xfe);
        bVar15 = false;
        bVar16 = iVar4 == 0;
        if (0 < iVar4) {
          do {
            pbVar14 = (byte *)((int)&local_120 + iVar4);
            bVar15 = *pbVar14 < 0x20;
            bVar3 = *pbVar14;
            bVar16 = bVar3 == 0x20;
            if (' ' < (char)bVar3) break;
            iVar4 = iVar4 + -1;
            bVar15 = iVar4 != -1;
            bVar16 = iVar4 == -1;
          } while (!bVar16);
          *(undefined *)((int)&local_120 + iVar4 + 1) = 10;
          *(undefined *)((int)&local_120 + iVar4 + 2) = 0;
        }
LAB_08154a37:
        iVar4 = 9;
        puVar12 = &local_120;
        do {
          if (iVar4 == 0) break;
          iVar4 = iVar4 + -1;
          bVar15 = *(byte *)puVar12 < (byte)*local_1a8;
          bVar16 = *(byte *)puVar12 == *local_1a8;
          puVar12 = (undefined4 *)((int)puVar12 + (uint)bVar17 * -2 + 1);
          local_1a8 = (char *)((byte *)local_1a8 + (uint)bVar17 * -2 + 1);
        } while (bVar16);
        cVar9 = (!bVar15 && !bVar16) - bVar15;
        goto LAB_08154a4f;
      }
LAB_081548fe:
      iVar4 = 0x2f0;
    }
  }
LAB_0815470d:
  ERR_put_error(9,0x6d,0x41,"pem_lib.c",iVar4);
  goto LAB_08154720;
  while( true ) {
    iVar4 = iVar4 + -1;
    bVar15 = *(byte *)puVar12 < *pbVar14;
    bVar16 = *(byte *)puVar12 == *pbVar14;
    puVar12 = (undefined4 *)((int)puVar12 + (uint)bVar17 * -2 + 1);
    pbVar14 = pbVar14 + (uint)bVar17 * -2 + 1;
    if (!bVar16) break;
code_r0x08154c0e:
    if (iVar4 == 0) break;
  }
  cVar9 = (!bVar15 && !bVar16) - bVar15;
  local_1b0 = local_1a4;
  local_1a4 = a_00;
LAB_08154a4f:
  pcVar10 = a->data;
  sVar5 = strlen(pcVar10);
  if (cVar9 == '\0') {
    iVar4 = strncmp(pcVar10,local_117,sVar5);
    bVar15 = iVar4 == 0;
    if (bVar15) {
      iVar4 = 6;
      pcVar10 = local_117 + sVar5;
      pcVar13 = "-----\n";
      do {
        if (iVar4 == 0) break;
        iVar4 = iVar4 + -1;
        bVar15 = *pcVar10 == *pcVar13;
        pcVar10 = pcVar10 + (uint)bVar17 * -2 + 1;
        pcVar13 = pcVar13 + (uint)bVar17 * -2 + 1;
      } while (bVar15);
      if (bVar15) {
        EVP_DecodeInit((EVP_ENCODE_CTX *)local_180);
        iVar4 = EVP_DecodeUpdate((EVP_ENCODE_CTX *)local_180,(uchar *)local_1a4->data,&local_184,
                                 (uchar *)local_1a4->data,local_184);
        if (iVar4 < 0) {
          iVar4 = 0x32d;
        }
        else {
          iVar4 = EVP_DecodeFinal((EVP_ENCODE_CTX *)local_180,(uchar *)(local_1a4->data + local_184)
                                  ,&local_188);
          if (-1 < iVar4) {
            local_184 = local_188 + local_184;
            if (local_184 != 0) {
              *name = a->data;
              *header = local_1b0->data;
              *data = (uchar *)local_1a4->data;
              *len = local_184;
              CRYPTO_free(a);
              CRYPTO_free(local_1b0);
              CRYPTO_free(local_1a4);
              iVar4 = 1;
              goto LAB_08154745;
            }
            goto LAB_08154720;
          }
          iVar4 = 0x332;
        }
        ERR_put_error(9,0x6d,100,"pem_lib.c",iVar4);
        goto LAB_08154720;
      }
    }
  }
  ERR_put_error(9,0x6d,0x66,"pem_lib.c",0x324);
LAB_08154720:
  BUF_MEM_free(a);
  BUF_MEM_free(local_1b0);
  BUF_MEM_free(local_1a4);
  iVar4 = 0;
LAB_08154745:
  if (local_20 != *(int *)(in_GS_OFFSET + 0x14)) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return iVar4;
}

