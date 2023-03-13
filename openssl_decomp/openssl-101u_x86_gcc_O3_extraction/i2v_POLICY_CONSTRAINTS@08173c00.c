
stack_st_CONF_VALUE *
i2v_POLICY_CONSTRAINTS(undefined4 param_1,ASN1_INTEGER **param_2,stack_st_CONF_VALUE *param_3)

{
  X509V3_add_value_int("Require Explicit Policy",*param_2,&param_3);
  X509V3_add_value_int("Inhibit Policy Mapping",param_2[1],&param_3);
  return param_3;
}

