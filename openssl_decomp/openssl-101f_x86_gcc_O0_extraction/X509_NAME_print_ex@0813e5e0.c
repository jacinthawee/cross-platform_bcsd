
int X509_NAME_print_ex(BIO *out,X509_NAME *nm,int indent,ulong flags)

{
  int iVar1;
  undefined *data;
  uint uVar2;
  X509_NAME_ENTRY *ne;
  int iVar3;
  ASN1_OBJECT *o;
  uint uVar4;
  uint uVar5;
  size_t sVar6;
  int iVar7;
  uint *puVar8;
  int iVar9;
  uint *puVar10;
  int in_GS_OFFSET;
  bool bVar11;
  undefined *local_c4;
  int local_c0;
  char *local_b8;
  int local_b0;
  int local_ac;
  int local_9c;
  size_t local_8c;
  int local_88;
  int local_84;
  uint local_70 [20];
  int local_20;
  
  local_20 = *(int *)(in_GS_OFFSET + 0x14);
  if (flags == 0) {
    indent = X509_NAME_print(out,nm,indent);
    goto LAB_0813e655;
  }
  if (indent < 0) {
    indent = 0;
    bVar11 = (flags & 0xf0000) == 0x20000;
    if (!bVar11) goto LAB_0813e68c;
LAB_0813e99d:
    local_c0 = 3;
    local_b0 = 2;
    local_c4 = &DAT_08226cc4;
    local_b8 = ", ";
    local_ac = 0;
  }
  else {
    if ((indent != 0) && (out != (BIO *)0x0)) {
      iVar9 = 0;
      do {
        iVar1 = BIO_write(out,&DAT_081f84a7,1);
        if (iVar1 != 1) goto LAB_0813e650;
        iVar9 = iVar9 + 1;
      } while (indent != iVar9);
    }
    bVar11 = (flags & 0xf0000) == 0x20000;
    if (bVar11) goto LAB_0813e99d;
LAB_0813e68c:
    uVar2 = flags & 0xf0000;
    if (uVar2 < 0x20000 || bVar11) {
      if (uVar2 != 0x10000) {
LAB_0813e650:
        indent = -1;
        goto LAB_0813e655;
      }
      local_c0 = 1;
      local_b0 = 1;
      local_c4 = &DAT_08223346;
      local_b8 = ",";
      local_ac = 0;
    }
    else if (uVar2 == 0x30000) {
      local_c0 = 3;
      local_b0 = 2;
      local_c4 = &DAT_08226cc4;
      local_b8 = "; ";
      local_ac = 0;
    }
    else {
      if (uVar2 != 0x40000) goto LAB_0813e650;
      local_c0 = 3;
      local_b0 = 1;
      local_c4 = &DAT_08226cc4;
      local_b8 = "\n";
      local_ac = indent;
    }
  }
  iVar9 = (-(uint)((flags & 0x800000) == 0) & 0xfffffffe) + 3;
  data = &UNK_08226ccb;
  if ((flags & 0x800000) == 0) {
    data = &UNK_081ecd53;
  }
  uVar2 = flags & 0x600000;
  local_84 = X509_NAME_entry_count(nm);
  if (0 < local_84) {
    local_84 = local_84 + -1;
    local_88 = -1;
    local_9c = 0;
    do {
      if ((flags & 0x100000) == 0) {
        ne = X509_NAME_get_entry(nm,local_9c);
        iVar1 = ne->set;
      }
      else {
        ne = X509_NAME_get_entry(nm,local_84);
        iVar1 = ne->set;
      }
      if (local_88 != -1) {
        if (iVar1 == local_88) {
          if (out != (BIO *)0x0) {
            iVar1 = BIO_write(out,local_c4,local_c0);
            if (local_c0 != iVar1) goto LAB_0813e650;
            iVar1 = ne->set;
          }
          indent = indent + local_c0;
        }
        else {
          if (out != (BIO *)0x0) {
            iVar1 = BIO_write(out,local_b8,local_b0);
            if (local_b0 != iVar1) goto LAB_0813e650;
            if (local_ac != 0) {
              iVar1 = 0;
              do {
                iVar3 = BIO_write(out,&DAT_081f84a7,1);
                if (iVar3 != 1) goto LAB_0813e650;
                iVar1 = iVar1 + 1;
              } while (local_ac != iVar1);
            }
            iVar1 = ne->set;
          }
          indent = local_ac + local_b0 + indent;
        }
      }
      local_88 = iVar1;
      o = X509_NAME_ENTRY_get_object(ne);
      X509_NAME_ENTRY_get_data(ne);
      iVar1 = OBJ_obj2nid(o);
      if (uVar2 != 0x600000) {
        if ((uVar2 == 0x400000) || (iVar1 == 0)) {
          OBJ_obj2txt((char *)local_70,0x50,o,1);
          puVar10 = local_70;
          do {
            puVar8 = puVar10;
            uVar4 = *puVar8 + 0xfefefeff & ~*puVar8;
            uVar5 = uVar4 & 0x80808080;
            puVar10 = puVar8 + 1;
          } while (uVar5 == 0);
          bVar11 = (uVar4 & 0x8080) == 0;
          if (bVar11) {
            uVar5 = uVar5 >> 0x10;
          }
          if (bVar11) {
            puVar10 = (uint *)((int)puVar8 + 6);
          }
          puVar8 = local_70;
          iVar3 = 0;
          local_8c = (int)puVar10 + ((-3 - (uint)CARRY1((byte)uVar5,(byte)uVar5)) - (int)puVar8);
LAB_0813eae3:
          if (out == (BIO *)0x0) {
            if (((int)local_8c < iVar3) && ((flags & 0x2000000) != 0)) goto LAB_0813eb27;
          }
          else {
            sVar6 = BIO_write(out,puVar8,local_8c);
            if (local_8c != sVar6) goto LAB_0813e650;
            if (((int)local_8c < iVar3) && ((flags & 0x2000000) != 0)) {
LAB_0813eb27:
              iVar3 = iVar3 - local_8c;
              if ((0 < iVar3) && (out != (BIO *)0x0)) {
                iVar1 = 0;
                do {
                  iVar7 = BIO_write(out,&DAT_081f84a7,1);
                  if (iVar7 != 1) goto LAB_0813e650;
                  iVar1 = iVar1 + 1;
                } while (iVar3 != iVar1);
              }
              indent = indent + iVar3;
              if (out == (BIO *)0x0) goto LAB_0813e90c;
            }
LAB_0813e8e9:
            iVar1 = BIO_write(out,data,iVar9);
            if (iVar9 != iVar1) goto LAB_0813e650;
          }
        }
        else {
          if (uVar2 == 0) {
            iVar3 = 10;
            puVar8 = (uint *)OBJ_nid2sn(iVar1);
            local_8c = strlen((char *)puVar8);
            goto LAB_0813eae3;
          }
          if (uVar2 == 0x200000) {
            iVar3 = 0x19;
            puVar8 = (uint *)OBJ_nid2ln(iVar1);
            local_8c = strlen((char *)puVar8);
            goto LAB_0813eae3;
          }
          if (out != (BIO *)0x0) {
            local_8c = BIO_write(out,&DAT_081ec74a,0);
            if (local_8c == 0) goto LAB_0813e8e9;
            goto LAB_0813e650;
          }
          local_8c = 0;
        }
LAB_0813e90c:
        indent = indent + local_8c + iVar9;
      }
      iVar1 = do_print_ex_constprop_2();
      if (iVar1 < 0) goto LAB_0813e650;
      local_84 = local_84 + -1;
      indent = indent + iVar1;
      local_9c = local_9c + 1;
    } while (local_84 != -1);
  }
LAB_0813e655:
  if (local_20 != *(int *)(in_GS_OFFSET + 0x14)) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return indent;
}

