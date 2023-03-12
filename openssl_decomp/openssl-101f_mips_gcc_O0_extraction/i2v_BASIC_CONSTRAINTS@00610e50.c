
undefined4 i2v_BASIC_CONSTRAINTS(undefined4 param_1,undefined4 *param_2,undefined4 param_3)

{
  undefined4 local_res8 [2];
  
  local_res8[0] = param_3;
  (*(code *)PTR_X509V3_add_value_bool_006aa918)(&DAT_0067a81c,*param_2,local_res8);
  (*(code *)PTR_X509V3_add_value_int_006aa1a8)("pathlen",param_2[1],local_res8);
  return local_res8[0];
}

