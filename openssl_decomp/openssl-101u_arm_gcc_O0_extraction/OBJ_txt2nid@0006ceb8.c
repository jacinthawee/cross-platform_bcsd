
int OBJ_txt2nid(char *s)

{
  undefined *puVar1;
  uint uVar2;
  int iVar3;
  int iVar4;
  _LHASH *p_Var5;
  _LHASH *a;
  void *pvVar6;
  int iVar7;
  _LHASH *p_Var8;
  int iVar9;
  int iVar10;
  int iVar11;
  _LHASH *local_48;
  _LHASH **local_44;
  _LHASH *local_40;
  _LHASH *local_3c;
  uint local_38;
  
  uVar2 = OBJ_sn2nid(s);
  if ((uVar2 == 0) && (uVar2 = OBJ_ln2nid(s), uVar2 == 0)) {
    iVar3 = a2d_ASN1_OBJECT((uchar *)0x0,0,s,-1);
    if (0 < iVar3) {
      iVar4 = ASN1_object_size(0,iVar3,6);
      p_Var5 = (_LHASH *)CRYPTO_malloc(iVar4,"obj_dat.c",0x1d6);
      if (p_Var5 != (_LHASH *)0x0) {
        local_48 = p_Var5;
        ASN1_put_object((uchar **)&local_48,0,iVar3,6,0);
        a2d_ASN1_OBJECT((uchar *)local_48,iVar3,s,-1);
        local_40 = p_Var5;
        a = (_LHASH *)d2i_ASN1_OBJECT((ASN1_OBJECT **)0x0,(uchar **)&local_40,iVar4);
        CRYPTO_free(p_Var5);
        goto LAB_0006cf42;
      }
    }
    a = (_LHASH *)0x0;
    p_Var5 = a;
    goto LAB_0006cf6e;
  }
  if (uVar2 < 0x398) {
    a = (_LHASH *)(&nid_objs + uVar2 * 6);
    p_Var5 = *(_LHASH **)(&DAT_0013fb48 + uVar2 * 0x18);
    if (p_Var5 == (_LHASH *)0x0) {
      ERR_put_error(8,0x67,0x65,"obj_dat.c",0x140);
      a = p_Var5;
    }
    else {
LAB_0006cf42:
      if (a != (_LHASH *)0x0) {
        p_Var5 = (_LHASH *)a->hash;
        if ((p_Var5 != (_LHASH *)0x0) || (uVar2 = a->num_nodes, uVar2 == 0)) goto LAB_0006cf6e;
        if (added != (_LHASH *)0x0) {
          local_40 = p_Var5;
          local_3c = a;
          pvVar6 = lh_retrieve(added,&local_40);
          if (pvVar6 != (void *)0x0) {
            p_Var5 = *(_LHASH **)(*(int *)((int)pvVar6 + 4) + 8);
            goto LAB_0006cf6e;
          }
          uVar2 = a->num_nodes;
          if (uVar2 == 0) {
            iVar3 = 0x359;
            p_Var8 = p_Var5;
            do {
              iVar4 = (int)((int)&p_Var8->b + iVar3) >> 1;
              iVar10 = *(int *)(obj_objs + iVar4 * 4);
              iVar11 = iVar10 * 2;
              if (*(int *)(&DAT_0013fb4c + iVar10 * 0x18) == 0) goto LAB_0006d022;
              if (*(int *)(&DAT_0013fb4c + iVar10 * 0x18) < 1) {
                p_Var8 = (_LHASH *)(iVar4 + 1);
                iVar4 = iVar3;
              }
              iVar3 = iVar4;
            } while ((int)p_Var8 < iVar4);
            goto LAB_0006cf6e;
          }
        }
        puVar1 = PTR_obj_objs_0006d0f4;
        iVar4 = 0;
        iVar3 = 0x359;
        do {
          iVar9 = iVar4 + iVar3 >> 1;
          iVar10 = *(int *)(puVar1 + iVar9 * 4);
          iVar11 = iVar10 * 2;
          iVar7 = uVar2 - *(int *)(&DAT_0013fb4c + iVar10 * 0x18);
          if (iVar7 == 0) {
            iVar7 = memcmp((void *)a->num_alloc_nodes,*(void **)(&DAT_0013fb50 + iVar10 * 0x18),
                           uVar2);
            if (-1 < iVar7) {
              if (iVar7 != 0) goto LAB_0006d06e;
              if (puVar1 + iVar9 * 4 != (undefined *)0x0) goto LAB_0006d022;
              goto LAB_0006cf6e;
            }
          }
          else if (-1 < iVar7) {
LAB_0006d06e:
            iVar4 = iVar9 + 1;
            iVar9 = iVar3;
          }
          iVar3 = iVar9;
        } while (iVar4 < iVar9);
        if (iVar7 == 0) {
LAB_0006d022:
          iVar3 = *(int *)(&DAT_0013fb48 + (iVar10 + iVar11) * 8);
          ASN1_OBJECT_free((ASN1_OBJECT *)a);
          return iVar3;
        }
        goto LAB_0006cf6e;
      }
    }
  }
  else {
    a = added;
    if (added != (_LHASH *)0x0) {
      local_44 = &local_40;
      local_48 = (_LHASH *)0x3;
      local_38 = uVar2;
      a = (_LHASH *)lh_retrieve(added,&local_48);
      if (a != (_LHASH *)0x0) {
        a = (_LHASH *)a->comp;
        goto LAB_0006cf42;
      }
      ERR_put_error(8,0x67,0x65,"obj_dat.c",0x14e);
    }
  }
  p_Var5 = (_LHASH *)0x0;
LAB_0006cf6e:
  ASN1_OBJECT_free((ASN1_OBJECT *)a);
  return (int)p_Var5;
}

