
void mime_parse_hdr(BIO *param_1)

{
  byte *pbVar1;
  _STACK *st;
  int iVar2;
  ushort **ppuVar3;
  size_t sVar4;
  ushort *puVar5;
  uint uVar6;
  byte *pbVar7;
  byte *__s;
  void *data;
  byte *pbVar8;
  byte *pbVar9;
  byte local_430 [1028];
  int local_2c;
  
  local_2c = __stack_chk_guard;
  st = sk_new(mime_hdr_cmp + 1);
  if (st != (_STACK *)0x0) {
    data = (void *)0x0;
    do {
      iVar2 = BIO_gets(param_1,(char *)local_430,0x400);
      if (iVar2 < 1) break;
      if (data == (void *)0x0) {
        pbVar7 = (byte *)(uint)local_430[0];
LAB_0010e99e:
        iVar2 = 1;
      }
      else {
        ppuVar3 = __ctype_b_loc();
        pbVar7 = (byte *)(uint)local_430[0];
        if (-1 < (int)((uint)(*ppuVar3)[(int)pbVar7] << 0x12)) goto LAB_0010e99e;
        iVar2 = 3;
      }
      __s = pbVar7;
      pbVar8 = local_430;
      pbVar9 = local_430;
      if (pbVar7 != (byte *)0x0) {
        if (pbVar7 == (byte *)0xd || pbVar7 == (byte *)0xa) {
          __s = (byte *)0x0;
        }
        else {
          __s = (byte *)0x0;
          do {
                    /* WARNING: Could not find normalized switch variable to match jumptable */
            switch(iVar2) {
            case 1:
              if (pbVar7 == (byte *)0x3a) {
                *pbVar9 = 0;
                uVar6 = (uint)*pbVar8;
                if (uVar6 != 0) {
                  if (uVar6 != 0x22) {
                    ppuVar3 = __ctype_b_loc();
                    __s = pbVar8;
                    do {
                      if (-1 < (int)((uint)(*ppuVar3)[uVar6] << 0x12)) goto LAB_0010eba4;
                      pbVar8 = __s + 1;
                      uVar6 = (uint)*pbVar8;
                      if (uVar6 == 0) goto LAB_0010ecc2;
                      __s = pbVar8;
                    } while (uVar6 != 0x22);
                  }
                  if ((pbVar8[1] != 0) && (__s = pbVar8 + 1, __s != (byte *)0x0)) {
LAB_0010eba4:
                    sVar4 = strlen((char *)__s);
                    uVar6 = sVar4 - 1;
                    pbVar7 = __s + uVar6;
                    if (CARRY4((uint)__s,uVar6) == false) {
                      uVar6 = (uint)__s[uVar6];
                      if (uVar6 != 0x22) {
                        ppuVar3 = __ctype_b_loc();
                        puVar5 = *ppuVar3;
                        pbVar8 = pbVar7;
                        do {
                          pbVar7 = pbVar8 + -1;
                          if (-1 < (int)((uint)puVar5[uVar6] << 0x12)) {
                            pbVar8 = pbVar9 + 1;
                            iVar2 = 2;
                            goto switchD_0010e9c4_caseD_3;
                          }
                          *pbVar8 = 0;
                          if (pbVar7 == __s + -1) goto LAB_0010ecc2;
                          uVar6 = (uint)*pbVar7;
                          pbVar8 = pbVar7;
                        } while (uVar6 != 0x22);
                      }
                      if (__s != pbVar7 + -1) {
                        pbVar8 = pbVar9 + 1;
                        *pbVar7 = 0;
                        iVar2 = 2;
                        break;
                      }
                    }
                  }
                }
LAB_0010ecc2:
                pbVar8 = pbVar9 + 1;
                __s = (byte *)0x0;
                iVar2 = 2;
              }
              break;
            case 2:
              if (pbVar7 == (byte *)0x3b) {
                *pbVar9 = 0;
                uVar6 = (uint)*pbVar8;
                if (uVar6 == 0) {
LAB_0010ecec:
                  pbVar7 = (byte *)0x0;
                }
                else {
                  if (uVar6 != 0x22) {
                    ppuVar3 = __ctype_b_loc();
                    pbVar7 = pbVar8;
                    do {
                      if (-1 < (int)((uint)(*ppuVar3)[uVar6] << 0x12)) goto LAB_0010eb00;
                      pbVar8 = pbVar7 + 1;
                      uVar6 = (uint)*pbVar8;
                      if (uVar6 == 0) goto LAB_0010ecec;
                      pbVar7 = pbVar8;
                    } while (uVar6 != 0x22);
                  }
                  if ((pbVar8[1] == 0) || (pbVar7 = pbVar8 + 1, pbVar7 == (byte *)0x0))
                  goto LAB_0010ecec;
LAB_0010eb00:
                  sVar4 = strlen((char *)pbVar7);
                  uVar6 = sVar4 - 1;
                  pbVar8 = pbVar7 + uVar6;
                  if (CARRY4((uint)pbVar7,uVar6) != false) goto LAB_0010ecec;
                  uVar6 = (uint)pbVar7[uVar6];
                  if (uVar6 != 0x22) {
                    ppuVar3 = __ctype_b_loc();
                    puVar5 = *ppuVar3;
                    pbVar1 = pbVar8;
                    do {
                      pbVar8 = pbVar1 + -1;
                      if (-1 < (int)((uint)puVar5[uVar6] << 0x12)) goto LAB_0010eb4c;
                      *pbVar1 = 0;
                      if (pbVar8 == pbVar7 + -1) goto LAB_0010ecec;
                      uVar6 = (uint)*pbVar8;
                      pbVar1 = pbVar8;
                    } while (uVar6 != 0x22);
                  }
                  if (pbVar7 == pbVar8 + -1) goto LAB_0010ecec;
                  *pbVar8 = 0;
                }
LAB_0010eb4c:
                pbVar8 = pbVar9 + 1;
                data = (void *)mime_hdr_new(__s,pbVar7);
                __s = (byte *)0x0;
                sk_push(st,data);
                iVar2 = 3;
              }
              else if (pbVar7 == (byte *)0x28) {
                iVar2 = 6;
              }
              break;
            case 3:
              if (pbVar7 == (byte *)0x3d) {
                *pbVar9 = 0;
                uVar6 = (uint)*pbVar8;
                if (uVar6 != 0) {
                  if (uVar6 != 0x22) {
                    ppuVar3 = __ctype_b_loc();
                    __s = pbVar8;
                    do {
                      if (-1 < (int)((uint)(*ppuVar3)[uVar6] << 0x12)) goto LAB_0010ea72;
                      pbVar8 = __s + 1;
                      uVar6 = (uint)*pbVar8;
                      if (uVar6 == 0) goto LAB_0010eca8;
                      __s = pbVar8;
                    } while (uVar6 != 0x22);
                  }
                  if ((pbVar8[1] != 0) && (__s = pbVar8 + 1, __s != (byte *)0x0)) {
LAB_0010ea72:
                    sVar4 = strlen((char *)__s);
                    uVar6 = sVar4 - 1;
                    pbVar7 = __s + uVar6;
                    if (CARRY4((uint)__s,uVar6) == false) {
                      uVar6 = (uint)__s[uVar6];
                      if (uVar6 != 0x22) {
                        ppuVar3 = __ctype_b_loc();
                        puVar5 = *ppuVar3;
                        pbVar8 = pbVar7;
                        do {
                          pbVar7 = pbVar8 + -1;
                          if (-1 < (int)((uint)puVar5[uVar6] << 0x12)) {
                            pbVar8 = pbVar9 + 1;
                            iVar2 = 4;
                            goto switchD_0010e9c4_caseD_3;
                          }
                          *pbVar8 = 0;
                          if (pbVar7 == __s + -1) goto LAB_0010eca8;
                          uVar6 = (uint)*pbVar7;
                          pbVar8 = pbVar7;
                        } while (uVar6 != 0x22);
                      }
                      if (__s != pbVar7 + -1) {
                        pbVar8 = pbVar9 + 1;
                        *pbVar7 = 0;
                        iVar2 = 4;
                        break;
                      }
                    }
                  }
                }
LAB_0010eca8:
                pbVar8 = pbVar9 + 1;
                __s = (byte *)0x0;
                iVar2 = 4;
              }
            }
switchD_0010e9c4_caseD_3:
            pbVar9 = pbVar9 + 1;
            pbVar7 = (byte *)(uint)*pbVar9;
          } while ((pbVar7 != (byte *)0x0) && (pbVar7 != (byte *)0xa && pbVar7 != (byte *)0xd));
        }
      }
      if (iVar2 == 2) {
        uVar6 = (uint)*pbVar8;
        if (uVar6 == 0) {
LAB_0010edfc:
          pbVar8 = (byte *)0x0;
        }
        else {
          if (uVar6 != 0x22) {
            ppuVar3 = __ctype_b_loc();
            do {
              if (-1 < (int)((uint)(*ppuVar3)[uVar6] << 0x12)) goto LAB_0010ed1a;
              pbVar8 = pbVar8 + 1;
              uVar6 = (uint)*pbVar8;
              if (uVar6 == 0) goto LAB_0010edfc;
            } while (uVar6 != 0x22);
          }
          if ((pbVar8[1] == 0) || (pbVar8 = pbVar8 + 1, pbVar8 == (byte *)0x0)) goto LAB_0010edfc;
LAB_0010ed1a:
          sVar4 = strlen((char *)pbVar8);
          uVar6 = sVar4 - 1;
          pbVar7 = pbVar8 + uVar6;
          if (CARRY4((uint)pbVar8,uVar6) != false) goto LAB_0010edfc;
          uVar6 = (uint)pbVar8[uVar6];
          if (uVar6 != 0x22) {
            ppuVar3 = __ctype_b_loc();
            puVar5 = *ppuVar3;
            pbVar1 = pbVar7;
            do {
              pbVar7 = pbVar1 + -1;
              if (-1 < (int)((uint)puVar5[uVar6] << 0x12)) goto LAB_0010ed5e;
              *pbVar1 = 0;
              if (pbVar7 == pbVar8 + -1) goto LAB_0010edfc;
              uVar6 = (uint)*pbVar7;
              pbVar1 = pbVar7;
            } while (uVar6 != 0x22);
          }
          if (pbVar8 == pbVar7 + -1) goto LAB_0010edfc;
          *pbVar7 = 0;
        }
LAB_0010ed5e:
        data = (void *)mime_hdr_new(__s,pbVar8);
        sk_push(st,data);
      }
      else if (iVar2 == 4) {
        uVar6 = (uint)*pbVar8;
        if (uVar6 != 0) {
          if (uVar6 != 0x22) {
            ppuVar3 = __ctype_b_loc();
            do {
              if (-1 < (int)((uint)(*ppuVar3)[uVar6] << 0x12)) goto LAB_0010ed9e;
              pbVar8 = pbVar8 + 1;
              uVar6 = (uint)*pbVar8;
              if (uVar6 == 0) goto LAB_0010ee14;
            } while (uVar6 != 0x22);
          }
          if ((pbVar8[1] != 0) && (pbVar8 = pbVar8 + 1, pbVar8 != (byte *)0x0)) {
LAB_0010ed9e:
            sVar4 = strlen((char *)pbVar8);
            uVar6 = sVar4 - 1;
            pbVar7 = pbVar8 + uVar6;
            if (CARRY4((uint)pbVar8,uVar6) == false) {
              uVar6 = (uint)pbVar8[uVar6];
              if (uVar6 != 0x22) {
                ppuVar3 = __ctype_b_loc();
                puVar5 = *ppuVar3;
                pbVar1 = pbVar7;
                do {
                  pbVar7 = pbVar1 + -1;
                  if (-1 < (int)((uint)puVar5[uVar6] << 0x12)) {
                    mime_hdr_addparam_isra_1((int)data + 8,__s,pbVar8);
                    goto LAB_0010e9f2;
                  }
                  *pbVar1 = 0;
                  if (pbVar7 == pbVar8 + -1) goto LAB_0010ee14;
                  uVar6 = (uint)*pbVar7;
                  pbVar1 = pbVar7;
                } while (uVar6 != 0x22);
              }
              if (pbVar8 != pbVar7 + -1) {
                *pbVar7 = 0;
                mime_hdr_addparam_isra_1((int)data + 8,__s,pbVar8);
                goto LAB_0010e9f2;
              }
            }
          }
        }
LAB_0010ee14:
        mime_hdr_addparam_isra_1((int)data + 8,__s,0);
      }
LAB_0010e9f2:
    } while (pbVar9 != local_430);
  }
  if (local_2c == __stack_chk_guard) {
    return;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail(st);
}

