// Name: Ryan Solana 
// Seneca Student ID: 126845171
// Seneca email: rsolana@myseneca.ca
// Date of completion: Sept 24, 2019
//
// I confirm that the content of this file is created by me,
// with the exception of the parts provided to me by my professor.

#ifndef SDDS_LVPAIR_H
#define SDDS_LVPAIR_H

namespace sdds {

	template<typename L, typename V>
	class LVPair {
		L m_Label;
		V m_Value;
	public:
		LVPair() : m_Label { "undefined" }, m_Value{ 0 }{ }

		LVPair(const L& aa, const V& bb) : m_Label(aa), m_Value(bb) { }
		const L& key() const {
			return m_Label;
		}
		const V& value() const {
			return m_Value;
		}
		void display(std::ostream& os) const {
			os << m_Label << " : " << m_Value << std::endl;
		}
	};

	template<typename L, typename V>
	std::ostream& operator<<(std::ostream& os, const sdds::LVPair<L, V>& pair) {
		pair.display(os);
		return os;
	}


}




#endif