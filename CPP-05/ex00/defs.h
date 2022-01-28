/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   defs.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kostya <kostya@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/16 12:09:17 by kostya            #+#    #+#             */
/*   Updated: 2022/01/16 12:17:25 by kostya           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DEFS_H
# define DEFS_H
# if __cplusplus <= 199711L
#  define __WUR __attribute__((warn_unused_result))
#  define noexcept throw()
#  define override
#  ifndef nullptr
#   define nullptr NULL
#  endif
#  define __CONST const
#  define __DEFAULT {}
#  define __DEFINE
#  define __OVERRIDE_VIRTUAL virtual

# else
#  define __WUR [[nodiscard]]
#  define __CONST
#  define __DEFAULT =default;
#  define __DEFINE {};
#  define __OVERRIDE_VIRTUAL

# endif /* 199711L */
#endif /* DEFS_H */
