/* Copyright 2015 Samsung Electronics Co., Ltd.
 * Copyright 2015 University of Szeged.
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *     http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

/*
 * Date built-in description
 */

#ifndef OBJECT_ID
# define OBJECT_ID(builtin_object_id)
#endif /* !OBJECT_ID */

#ifndef OBJECT_VALUE
# define OBJECT_VALUE(name, obj_getter, prop_writable, prop_enumerable, prop_configurable)
#endif /* !OBJECT_VALUE */

#ifndef NUMBER_VALUE
# define NUMBER_VALUE(name, number_value, prop_writable, prop_enumerable, prop_configurable)
#endif /* !NUMBER_VALUE */

#ifndef ROUTINE
# define ROUTINE(name, c_function_name, args_number, length_prop_value)
#endif /* !ROUTINE */

/* Object identifier */
OBJECT_ID (ECMA_BUILTIN_ID_DATE)

// ECMA-262 v5, 15.9.4.1
OBJECT_VALUE (LIT_MAGIC_STRING_PROTOTYPE,
              ecma_builtin_get (ECMA_BUILTIN_ID_DATE_PROTOTYPE),
              ECMA_PROPERTY_NOT_WRITABLE,
              ECMA_PROPERTY_NOT_ENUMERABLE,
              ECMA_PROPERTY_NOT_CONFIGURABLE)

NUMBER_VALUE (LIT_MAGIC_STRING_LENGTH,
              7,
              ECMA_PROPERTY_NOT_WRITABLE,
              ECMA_PROPERTY_NOT_ENUMERABLE,
              ECMA_PROPERTY_NOT_CONFIGURABLE)

ROUTINE (LIT_MAGIC_STRING_PARSE, ecma_builtin_date_parse, 1, 1)
ROUTINE (LIT_MAGIC_STRING_UTC_U, ecma_builtin_date_utc, NON_FIXED, 7)
ROUTINE (LIT_MAGIC_STRING_NOW, ecma_builtin_date_now, 0, 0)

#undef OBJECT_ID
#undef SIMPLE_VALUE
#undef NUMBER_VALUE
#undef STRING_VALUE
#undef OBJECT_VALUE
#undef CP_UNIMPLEMENTED_VALUE
#undef ROUTINE
