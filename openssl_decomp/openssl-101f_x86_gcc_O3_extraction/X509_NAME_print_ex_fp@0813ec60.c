
int X509_NAME_print_ex_fp(FILE *fp,X509_NAME *nm,int indent,ulong flags)

{
  BIO *bp;
  uint uVar1;
  undefined *__ptr;
  uint uVar2;
  X509_NAME_ENTRY *ne;
  size_t sVar3;
  ASN1_OBJECT *o;
  uint uVar4;
  uint uVar5;
  uint *puVar6;
  uint *puVar7;
  int iVar8;
  size_t sVar9;
  int iVar10;
  int iVar11;
  int in_GS_OFFSET;
  bool bVar12;
  undefined *local_cc;
  size_t local_c8;
  int local_c4;
  int local_c0;
  size_t local_b8;
  char *local_b4;
  size_t local_a0;
  int local_94;
  int local_88;
  int local_84;
  uint local_70 [20];
  int local_20;
  
  local_20 = *(int *)(in_GS_OFFSET + 0x14);
  if (flags == 0) {
    bp = BIO_new_fp(fp,0);
    if (bp != (BIO *)0x0) {
      indent = X509_NAME_print(bp,nm,indent);
      BIO_free(bp);
      goto LAB_0813eeb1;
    }
LAB_0813eeac:
    indent = -1;
  }
  else {
    if (indent < 0) {
      indent = 0;
    }
    else if ((indent != 0) && (fp != (FILE *)0x0)) {
      iVar8 = 0;
      do {
        sVar9 = fwrite(&DAT_081f84a7,1,1,fp);
        if (sVar9 != 1) goto LAB_0813eeac;
        iVar8 = iVar8 + 1;
      } while (indent != iVar8);
    }
    uVar1 = flags & 0xf0000;
    if (uVar1 == 0x20000) {
      local_b8 = 2;
      local_c8 = 3;
      iVar8 = 0;
      local_c4 = 3;
      local_c0 = 2;
      local_cc = &DAT_08226cc4;
      local_b4 = ", ";
    }
    else if (uVar1 < 0x20001) {
      if (uVar1 != 0x10000) goto LAB_0813eeac;
      local_b8 = 1;
      local_c8 = 1;
      iVar8 = 0;
      local_c4 = 1;
      local_c0 = 1;
      local_cc = &DAT_08223346;
      local_b4 = ",";
    }
    else if (uVar1 == 0x30000) {
      local_b8 = 2;
      local_c8 = 3;
      iVar8 = 0;
      local_c4 = 3;
      local_c0 = 2;
      local_cc = &DAT_08226cc4;
      local_b4 = "; ";
    }
    else {
      if (uVar1 != 0x40000) goto LAB_0813eeac;
      local_b8 = 1;
      local_c8 = 3;
      local_c4 = 3;
      local_c0 = 1;
      local_cc = &DAT_08226cc4;
      local_b4 = "\n";
      iVar8 = indent;
    }
    uVar1 = flags & 0x800000;
    sVar9 = (-(uint)(uVar1 == 0) & 0xfffffffe) + 3;
    __ptr = &DAT_08226ccb;
    if (uVar1 == 0) {
      __ptr = &DAT_081ecd53;
    }
    uVar2 = flags & 0x600000;
    local_84 = X509_NAME_entry_count(nm);
    if (0 < local_84) {
      local_84 = local_84 + -1;
      local_88 = -1;
      local_94 = 0;
      do {
        if ((flags & 0x100000) == 0) {
          ne = X509_NAME_get_entry(nm,local_94);
          iVar10 = ne->set;
        }
        else {
          ne = X509_NAME_get_entry(nm,local_84);
          iVar10 = ne->set;
        }
        if (local_88 != -1) {
          if (iVar10 == local_88) {
            if (fp != (FILE *)0x0) {
              sVar3 = fwrite(local_cc,1,local_c8,fp);
              if (local_c8 != sVar3) goto LAB_0813eeac;
              iVar10 = ne->set;
            }
            indent = indent + local_c4;
          }
          else {
            if (fp != (FILE *)0x0) {
              sVar3 = fwrite(local_b4,1,local_b8,fp);
              if (sVar3 != local_b8) goto LAB_0813eeac;
              if (iVar8 == 0) {
                iVar10 = ne->set;
              }
              else {
                iVar10 = 0;
                do {
                  sVar3 = fwrite(&DAT_081f84a7,1,1,fp);
                  if (sVar3 != 1) goto LAB_0813eeac;
                  iVar10 = iVar10 + 1;
                } while (iVar8 != iVar10);
                iVar10 = ne->set;
              }
            }
            indent = local_c0 + indent + iVar8;
          }
        }
        local_88 = iVar10;
        o = X509_NAME_ENTRY_get_object(ne);
        X509_NAME_ENTRY_get_data(ne);
        iVar10 = OBJ_obj2nid(o);
        if (uVar2 != 0x600000) {
          if ((uVar2 == 0x400000) || (iVar10 == 0)) {
            OBJ_obj2txt((char *)local_70,0x50,o,1);
            puVar7 = local_70;
            do {
              puVar6 = puVar7;
              uVar4 = *puVar6 + 0xfefefeff & ~*puVar6;
              uVar5 = uVar4 & 0x80808080;
              puVar7 = puVar6 + 1;
            } while (uVar5 == 0);
            bVar12 = (uVar4 & 0x8080) == 0;
            if (bVar12) {
              uVar5 = uVar5 >> 0x10;
            }
            if (bVar12) {
              puVar7 = (uint *)((int)puVar6 + 6);
            }
            puVar6 = local_70;
            iVar11 = 0;
            local_a0 = (int)puVar7 + ((-3 - (uint)CARRY1((byte)uVar5,(byte)uVar5)) - (int)puVar6);
joined_r0x0813f242:
            if (fp == (FILE *)0x0) {
              if (((int)local_a0 < iVar11) && ((flags & 0x2000000) != 0)) {
LAB_0813f19d:
                iVar11 = iVar11 - local_a0;
                if ((0 < iVar11) && (fp != (FILE *)0x0)) {
                  iVar10 = 0;
                  do {
                    sVar3 = fwrite(&DAT_081f84a7,1,1,fp);
                    if (sVar3 != 1) goto LAB_0813eeac;
                    iVar10 = iVar10 + 1;
                  } while (iVar11 != iVar10);
                }
                indent = indent + iVar11;
                if (fp != (FILE *)0x0) goto LAB_0813f020;
              }
            }
            else {
              sVar3 = fwrite(puVar6,1,local_a0,fp);
              if (sVar3 != local_a0) goto LAB_0813eeac;
              if (((int)local_a0 < iVar11) && ((flags & 0x2000000) != 0)) goto LAB_0813f19d;
LAB_0813f020:
              sVar3 = fwrite(__ptr,1,sVar9,fp);
              if (sVar9 != sVar3) goto LAB_0813eeac;
            }
          }
          else {
            if (uVar2 == 0) {
              iVar11 = 10;
              puVar6 = (uint *)OBJ_nid2sn(iVar10);
              local_a0 = strlen((char *)puVar6);
              goto joined_r0x0813f242;
            }
            if (uVar2 == 0x200000) {
              iVar11 = 0x19;
              puVar6 = (uint *)OBJ_nid2ln(iVar10);
              local_a0 = strlen((char *)puVar6);
              goto joined_r0x0813f242;
            }
            if (fp != (FILE *)0x0) {
              sVar3 = fwrite(&DAT_081ec74a,1,0,fp);
              if (sVar3 == 0) {
                local_a0 = 0;
                goto LAB_0813f020;
              }
              goto LAB_0813eeac;
            }
            local_a0 = 0;
          }
          indent = indent + local_a0 + (-(uint)(uVar1 == 0) & 0xfffffffe) + 3;
        }
        iVar10 = do_print_ex_constprop_3();
        if (iVar10 < 0) goto LAB_0813eeac;
        local_84 = local_84 + -1;
        indent = indent + iVar10;
        local_94 = local_94 + 1;
      } while (local_84 != -1);
    }
  }
LAB_0813eeb1:
  if (local_20 == *(int *)(in_GS_OFFSET + 0x14)) {
    return indent;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}

