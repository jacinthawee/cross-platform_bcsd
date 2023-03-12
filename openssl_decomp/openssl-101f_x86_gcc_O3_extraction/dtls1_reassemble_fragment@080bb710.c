
uint __regparm3 dtls1_reassemble_fragment(int param_1,undefined4 *param_2,undefined4 *param_3)

{
  char cVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  byte bVar4;
  uint uVar5;
  int iVar6;
  int iVar7;
  undefined4 *ptr;
  void *__s;
  void *pvVar8;
  uint uVar9;
  uint uVar10;
  byte *pbVar11;
  size_t __n;
  int in_GS_OFFSET;
  pitem *local_138;
  uint local_134;
  undefined4 local_128;
  int local_124;
  undefined local_120 [256];
  int local_20;
  
  uVar10 = param_2[4];
  local_20 = *(int *)(in_GS_OFFSET + 0x14);
  uVar5 = param_2[3] + uVar10;
  if (uVar5 < (uint)param_2[1] || uVar5 == param_2[1]) {
    uVar9 = *(uint *)(param_1 + 0x108);
    if ((int)uVar9 < 0x454d) {
      uVar9 = 0x454c;
    }
    if (uVar9 < uVar5) goto LAB_080bb753;
    local_128 = 0;
    local_124 = (uint)CONCAT11((char)*(undefined2 *)(param_2 + 2),
                               (char)((ushort)*(undefined2 *)(param_2 + 2) >> 8)) << 0x10;
    local_138 = pqueue_find(*(pqueue *)(*(int *)(param_1 + 0x5c) + 0x244),(uchar *)&local_128);
    if (local_138 == (pitem *)0x0) {
      __n = param_2[1];
      ptr = (undefined4 *)CRYPTO_malloc(0x34,"d1_both.c",0xb3);
      if (ptr != (undefined4 *)0x0) {
        if (__n == 0) {
          ptr[0xb] = 0;
          __s = CRYPTO_malloc(0,"d1_both.c",199);
          if (__s != (void *)0x0) {
LAB_080bbafa:
            memset(__s,0,__n);
            ptr[0xc] = __s;
            *ptr = *param_2;
            uVar2 = param_2[1];
            ptr[1] = uVar2;
            ptr[2] = param_2[2];
            ptr[3] = param_2[3];
            ptr[4] = param_2[4];
            ptr[5] = param_2[5];
            ptr[6] = param_2[6];
            ptr[7] = param_2[7];
            ptr[8] = param_2[8];
            ptr[9] = param_2[9];
            uVar3 = param_2[10];
            ptr[4] = uVar2;
            ptr[3] = 0;
            ptr[10] = uVar3;
            goto LAB_080bb7e9;
          }
        }
        else {
          pvVar8 = CRYPTO_malloc(__n,"d1_both.c",0xb9);
          if (pvVar8 != (void *)0x0) {
            __n = __n + 7 >> 3;
            ptr[0xb] = pvVar8;
            __s = CRYPTO_malloc(__n,"d1_both.c",199);
            if (__s != (void *)0x0) goto LAB_080bbafa;
            CRYPTO_free(pvVar8);
          }
        }
        CRYPTO_free(ptr);
      }
      goto LAB_080bb753;
    }
    ptr = (undefined4 *)local_138->data;
    if (ptr[0xc] == 0) {
      for (; uVar10 != 0; uVar10 = uVar10 - uVar5) {
        uVar5 = 0x100;
        if (uVar10 < 0x101) {
          uVar5 = uVar10;
        }
        uVar5 = (**(code **)(*(int *)(param_1 + 8) + 0x34))(param_1,0x16,local_120,uVar5,0);
        if ((int)uVar5 < 1) goto LAB_080bb943;
      }
      uVar10 = 0xfffffffd;
      goto LAB_080bb763;
    }
LAB_080bb7e9:
    uVar5 = (**(code **)(*(int *)(param_1 + 8) + 0x34))(param_1,0x16,param_2[3] + ptr[0xb],uVar10,0)
    ;
    if ((0 < (int)uVar5) && (uVar5 == uVar10)) {
      if ((int)uVar10 < 9) {
        iVar6 = param_2[3];
        if (iVar6 < (int)(uVar10 + iVar6)) {
          do {
            pbVar11 = (byte *)((iVar6 >> 3) + ptr[0xc]);
            bVar4 = (byte)iVar6;
            iVar6 = iVar6 + 1;
            *pbVar11 = *pbVar11 | (byte)(1 << (bVar4 & 7));
          } while (iVar6 < (int)(param_2[3] + uVar10));
        }
      }
      else {
        pbVar11 = (byte *)(((int)param_2[3] >> 3) + ptr[0xc]);
        *pbVar11 = *pbVar11 | *(byte *)((int)&bitmask_start_values + (param_2[3] & 7));
        local_134 = param_2[3] + uVar10;
        iVar7 = ((int)param_2[3] >> 3) + 1;
        iVar6 = (int)(local_134 - 1) >> 3;
        if (iVar7 < iVar6) {
          do {
            *(undefined *)(ptr[0xc] + iVar7) = 0xff;
            iVar7 = iVar7 + 1;
            local_134 = param_2[3] + uVar10;
            iVar6 = (int)(local_134 - 1) >> 3;
          } while (iVar7 < iVar6);
        }
        *(byte *)(iVar6 + ptr[0xc]) =
             *(byte *)(iVar6 + ptr[0xc]) | *(byte *)((int)&bitmask_end_values + (local_134 & 7));
      }
      uVar10 = param_2[1];
      if ((int)uVar10 < 1) {
        OpenSSLDie("d1_both.c",0x294,"((long)msg_hdr->msg_len) > 0");
        uVar10 = param_2[1];
      }
      pvVar8 = (void *)ptr[0xc];
      iVar6 = (int)(uVar10 - 1) >> 3;
      if (*(char *)((int)pvVar8 + iVar6) == *(char *)((int)&bitmask_end_values + (uVar10 & 7))) {
        iVar7 = iVar6 + -1;
        if (iVar7 < 0) {
LAB_080bba6a:
          CRYPTO_free(pvVar8);
          ptr[0xc] = 0;
        }
        else {
          cVar1 = *(char *)((int)pvVar8 + iVar6 + -1);
          while (cVar1 == -1) {
            iVar7 = iVar7 + -1;
            if (iVar7 == -1) goto LAB_080bba6a;
            cVar1 = *(char *)((int)pvVar8 + iVar7);
          }
        }
      }
      uVar10 = 0xfffffffd;
      if (local_138 != (pitem *)0x0) goto LAB_080bb763;
      local_128 = 0;
      local_124 = (uint)CONCAT11((char)*(undefined2 *)(param_2 + 2),
                                 (char)((ushort)*(undefined2 *)(param_2 + 2) >> 8)) << 0x10;
      local_138 = pitem_new((uchar *)&local_128,ptr);
      if (local_138 != (pitem *)0x0) {
        pqueue_insert(*(pqueue *)(*(int *)(param_1 + 0x5c) + 0x244),local_138);
        goto LAB_080bb763;
      }
    }
LAB_080bb943:
    if (ptr[5] != 0) {
      EVP_CIPHER_CTX_free((EVP_CIPHER_CTX *)ptr[6]);
      EVP_MD_CTX_destroy((EVP_MD_CTX *)ptr[7]);
    }
    if ((void *)ptr[0xb] != (void *)0x0) {
      CRYPTO_free((void *)ptr[0xb]);
    }
    if ((void *)ptr[0xc] != (void *)0x0) {
      CRYPTO_free((void *)ptr[0xc]);
    }
    CRYPTO_free(ptr);
    uVar10 = uVar5;
    if (local_138 != (pitem *)0x0) {
      CRYPTO_free(local_138);
    }
  }
  else {
LAB_080bb753:
    uVar10 = 0xffffffff;
  }
  *param_3 = 0;
LAB_080bb763:
  if (local_20 != *(int *)(in_GS_OFFSET + 0x14)) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return uVar10;
}

